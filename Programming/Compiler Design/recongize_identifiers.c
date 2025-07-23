#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Token types
typedef enum {
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_EOF
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char value[256];
    int line;
    int column;
} Token;

// Function prototypes
void skipWhitespace(FILE* file, int* line, int* column);
Token getIdentifier(FILE* file, int* line, int* column, char firstChar);
Token getNumber(FILE* file, int* line, int* column, char firstChar);
void printToken(Token token, int tokenNumber);
const char* getTokenTypeName(TokenType type);

int main() {
    char filename[256];
    FILE* file;
    int line = 1, column = 1;
    int identifierCount = 0, numberCount = 0, totalTokens = 0;
    
    printf("Identifier and Number Recognizer\n");
    printf("================================\n");
    printf("Enter the C source file name: ");
    scanf("%255s", filename);
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 1;
    }
    
    printf("\nRecognized Identifiers and Numbers from '%s':\n", filename);
    printf("%-5s %-12s %-30s %-8s %-8s\n", "No.", "Type", "Value", "Line", "Column");
    printf("---------------------------------------------------------------\n");
    
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        // Skip whitespace
        if (isspace(ch)) {
            if (ch == '\n') {
                line++;
                column = 1;
            } else {
                column++;
            }
            continue;
        }
        
        // Check for identifier (letter or underscore)
        if (isalpha(ch) || ch == '_') {
            Token token = getIdentifier(file, &line, &column, ch);
            totalTokens++;
            identifierCount++;
            printToken(token, totalTokens);
        }
        // Check for number (digit)
        else if (isdigit(ch)) {
            Token token = getNumber(file, &line, &column, ch);
            totalTokens++;
            numberCount++;
            printToken(token, totalTokens);
        }
        // Skip other characters (operators, punctuation, etc.)
        else {
            column++;
        }
    }
    
    printf("---------------------------------------------------------------\n");
    printf("Summary:\n");
    printf("Total Identifiers: %d\n", identifierCount);
    printf("Total Numbers: %d\n", numberCount);
    printf("Total Tokens: %d\n", totalTokens);
    
    fclose(file);
    return 0;
}

Token getIdentifier(FILE* file, int* line, int* column, char firstChar) {
    Token token;
    int i = 0;
    
    // Set token properties
    token.type = TOKEN_IDENTIFIER;
    token.line = *line;
    token.column = *column;
    
    // Add first character
    token.value[i++] = firstChar;
    (*column)++;
    
    // Continue reading while character is letter, digit, or underscore
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            if (i < 255) { // Prevent buffer overflow
                token.value[i++] = ch;
            }
            (*column)++;
        } else {
            // Put back the character that's not part of identifier
            ungetc(ch, file);
            break;
        }
    }
    
    token.value[i] = '\0'; // Null terminate
    return token;
}

Token getNumber(FILE* file, int* line, int* column, char firstChar) {
    Token token;
    int i = 0;
    int hasDecimal = 0;
    
    // Set initial token properties
    token.type = TOKEN_INTEGER;
    token.line = *line;
    token.column = *column;
    
    // Add first digit
    token.value[i++] = firstChar;
    (*column)++;
    
    // Continue reading digits and possibly decimal point
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (isdigit(ch)) {
            if (i < 255) { // Prevent buffer overflow
                token.value[i++] = ch;
            }
            (*column)++;
        } else if (ch == '.' && !hasDecimal) {
            // Check if next character is a digit to confirm it's a decimal number
            int nextCh = fgetc(file);
            if (isdigit(nextCh)) {
                hasDecimal = 1;
                token.type = TOKEN_FLOAT;
                if (i < 254) { // Leave space for next digit
                    token.value[i++] = ch;
                    token.value[i++] = nextCh;
                }
                (*column) += 2;
            } else {
                // Not a decimal number, put back both characters
                ungetc(nextCh, file);
                ungetc(ch, file);
                break;
            }
        } else {
            // Put back the character that's not part of number
            ungetc(ch, file);
            break;
        }
    }
    
    token.value[i] = '\0'; // Null terminate
    return token;
}

void printToken(Token token, int tokenNumber) {
    printf("%-5d %-12s %-30s %-8d %-8d\n", 
           tokenNumber,
           getTokenTypeName(token.type), 
           token.value, 
           token.line, 
           token.column);
}

const char* getTokenTypeName(TokenType type) {
    switch (type) {
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_INTEGER: return "INTEGER";
        case TOKEN_FLOAT: return "FLOAT";
        case TOKEN_EOF: return "EOF";
        default: return "UNKNOWN";
    }
}