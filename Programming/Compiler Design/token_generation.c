#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Token types
typedef enum {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_INTEGER,
    TOKEN_FLOAT,
    TOKEN_OPERATOR,
    TOKEN_DELIMITER,
    TOKEN_STRING_LITERAL,
    TOKEN_CHAR_LITERAL,
    TOKEN_COMMENT,
    TOKEN_EOF,
    TOKEN_UNKNOWN
} TokenType;

typedef struct {
    TokenType type;
    char value[256];
    int line;
    int column;
} Token;

// C Keywords
const char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

// Operators
const char* operators[] = {
    "++", "--", "==", "!=", "<=", ">=", "&&", "||", "<<", ">>",
    "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=",
    "+", "-", "*", "/", "%", "=", "<", ">", "!", "&", "|", "^", "~", "?"
};

// Delimiters
const char* delimiters[] = {
    "(", ")", "{", "}", "[", "]", ";", ",", ".", ":", "#"
};

// Function prototypes
int isKeyword(const char* str);
int isOperator(const char* str);
int isDelimiter(char ch);
void skipWhitespace(FILE* file, int* line, int* column);
void skipComment(FILE* file, int* line, int* column);
Token getNextToken(FILE* file, int* line, int* column);
void printToken(Token token);
const char* getTokenTypeName(TokenType type);

int main() {
    char filename[256];
    FILE* file;
    Token token;
    int line = 1, column = 1;
    int tokenCount = 0;

    printf("C Program Tokenizer\n");
    printf("===================\n");
    printf("Enter the C source file name: ");
    scanf("%255s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 1;
    }

    printf("\nTokens found in '%s':\n", filename);
    printf("%-5s %-15s %-20s %-10s %-10s\n", "No.", "Type", "Value", "Line", "Column");
    printf("----------------------------------------------------------------\n");

    do {
        token = getNextToken(file, &line, &column);
        if (token.type != TOKEN_EOF) {
            tokenCount++;
            printf("%-5d ", tokenCount);
            printToken(token);
        }
    } while (token.type != TOKEN_EOF);

    printf("----------------------------------------------------------------\n");
    printf("Total tokens found: %d\n", tokenCount);

    fclose(file);
    return 0;
}

int isKeyword(const char* str) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(const char* str) {
    int numOperators = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < numOperators; i++) {
        if (strcmp(str, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isDelimiter(char ch) {
    int numDelimiters = sizeof(delimiters) / sizeof(delimiters[0]);
    for (int i = 0; i < numDelimiters; i++) {
        if (ch == delimiters[i][0]) {
            return 1;
        }
    }
    return 0;
}

void skipWhitespace(FILE* file, int* line, int* column) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\t') {
            (*column)++;
        } else if (ch == '\n') {
            (*line)++;
            *column = 1;
        } else {
            ungetc(ch, file);
            break;
        }
    }
}

void skipComment(FILE* file, int* line, int* column) {
    int ch = fgetc(file);
    (*column)++;
    
    if (ch == '/') {
        // Single line comment
        while ((ch = fgetc(file)) != EOF && ch != '\n') {
            (*column)++;
        }
        if (ch == '\n') {
            (*line)++;
            *column = 1;
        }
    } else if (ch == '*') {
        // Multi-line comment
        while ((ch = fgetc(file)) != EOF) {
            if (ch == '\n') {
                (*line)++;
                *column = 1;
            } else {
                (*column)++;
            }
            
            if (ch == '*') {
                ch = fgetc(file);
                if (ch == '/') {
                    (*column)++;
                    break;
                } else {
                    ungetc(ch, file);
                }
            }
        }
    } else {
        ungetc(ch, file);
    }
}

Token getNextToken(FILE* file, int* line, int* column) {
    Token token;
    token.line = *line;
    token.column = *column;
    token.value[0] = '\0';
    
    skipWhitespace(file, line, column);
    
    int ch = fgetc(file);
    if (ch == EOF) {
        token.type = TOKEN_EOF;
        strcpy(token.value, "EOF");
        return token;
    }
    
    token.line = *line;
    token.column = *column;
    (*column)++;
    
    // Check for comments
    if (ch == '/') {
        int nextCh = fgetc(file);
        if (nextCh == '/' || nextCh == '*') {
            ungetc(nextCh, file);
            ungetc(ch, file);
            (*column)--;
            skipComment(file, line, column);
            return getNextToken(file, line, column);
        } else {
            ungetc(nextCh, file);
        }
    }
    
    // String literals
    if (ch == '"') {
        int i = 0;
        token.value[i++] = ch;
        while ((ch = fgetc(file)) != EOF && ch != '"' && i < 255) {
            token.value[i++] = ch;
            (*column)++;
            if (ch == '\\') { // Handle escape sequences
                ch = fgetc(file);
                if (ch != EOF) {
                    token.value[i++] = ch;
                    (*column)++;
                }
            }
        }
        if (ch == '"') {
            token.value[i++] = ch;
            (*column)++;
        }
        token.value[i] = '\0';
        token.type = TOKEN_STRING_LITERAL;
        return token;
    }
    
    // Character literals
    if (ch == '\'') {
        int i = 0;
        token.value[i++] = ch;
        while ((ch = fgetc(file)) != EOF && ch != '\'' && i < 255) {
            token.value[i++] = ch;
            (*column)++;
            if (ch == '\\') { // Handle escape sequences
                ch = fgetc(file);
                if (ch != EOF) {
                    token.value[i++] = ch;
                    (*column)++;
                }
            }
        }
        if (ch == '\'') {
            token.value[i++] = ch;
            (*column)++;
        }
        token.value[i] = '\0';
        token.type = TOKEN_CHAR_LITERAL;
        return token;
    }
    
    // Numbers (integers and floats)
    if (isdigit(ch)) {
        int i = 0;
        int isFloat = 0;
        
        token.value[i++] = ch;
        while ((ch = fgetc(file)) != EOF && (isdigit(ch) || ch == '.')) {
            if (ch == '.') {
                if (isFloat) break; // Second dot, not part of number
                isFloat = 1;
            }
            token.value[i++] = ch;
            (*column)++;
        }
        ungetc(ch, file);
        token.value[i] = '\0';
        token.type = isFloat ? TOKEN_FLOAT : TOKEN_INTEGER;
        return token;
    }
    
    // Identifiers and keywords
    if (isalpha(ch) || ch == '_') {
        int i = 0;
        token.value[i++] = ch;
        
        while ((ch = fgetc(file)) != EOF && (isalnum(ch) || ch == '_')) {
            token.value[i++] = ch;
            (*column)++;
        }
        ungetc(ch, file);
        token.value[i] = '\0';
        
        token.type = isKeyword(token.value) ? TOKEN_KEYWORD : TOKEN_IDENTIFIER;
        return token;
    }
    
    // Operators (check multi-character first)
    if (strchr("+-*/%=<>!&|^~?", ch)) {
        char temp[3];
        temp[0] = ch;
        temp[1] = fgetc(file);
        temp[2] = '\0';
        
        if (temp[1] != EOF && isOperator(temp)) {
            strcpy(token.value, temp);
            (*column)++;
        } else {
            ungetc(temp[1], file);
            temp[1] = '\0';
            strcpy(token.value, temp);
        }
        token.type = TOKEN_OPERATOR;
        return token;
    }
    
    // Delimiters
    if (isDelimiter(ch)) {
        token.value[0] = ch;
        token.value[1] = '\0';
        token.type = TOKEN_DELIMITER;
        return token;
    }
    
    // Unknown character
    token.value[0] = ch;
    token.value[1] = '\0';
    token.type = TOKEN_UNKNOWN;
    return token;
}

void printToken(Token token) {
    printf("%-15s %-20s %-10d %-10d\n", 
           getTokenTypeName(token.type), 
           token.value, 
           token.line, 
           token.column);
}

const char* getTokenTypeName(TokenType type) {
    switch (type) {
        case TOKEN_KEYWORD: return "KEYWORD";
        case TOKEN_IDENTIFIER: return "IDENTIFIER";
        case TOKEN_INTEGER: return "INTEGER";
        case TOKEN_FLOAT: return "FLOAT";
        case TOKEN_OPERATOR: return "OPERATOR";
        case TOKEN_DELIMITER: return "DELIMITER";
        case TOKEN_STRING_LITERAL: return "STRING";
        case TOKEN_CHAR_LITERAL: return "CHARACTER";
        case TOKEN_COMMENT: return "COMMENT";
        case TOKEN_EOF: return "EOF";
        case TOKEN_UNKNOWN: return "UNKNOWN";
        default: return "UNKNOWN";
    }
}