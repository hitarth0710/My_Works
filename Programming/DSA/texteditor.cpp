#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000

// Define a structure for a stack node
struct StackNode {
    char data;
    struct StackNode* next;
};

// Function to create a new stack node
struct StackNode* createStackNode(char data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return (root == NULL);
}

// Function to push a character onto the stack
void push(struct StackNode** root, char data) {
    struct StackNode* newNode = createStackNode(data);
    newNode->next = *root;
    *root = newNode;
}

// Function to pop a character from the stack
char pop(struct StackNode** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty.\n");
        return '\0';
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    char popped = temp->data;
    free(temp);
    return popped;
}

// Function to implement a simple text editor using a stack
void textEditor() {
    struct StackNode* undoStack = NULL;
    struct StackNode* redoStack = NULL;
    char text[MAX_TEXT_LENGTH] = "";  // Initial text is empty

    while (1) {
        system("cls");
        printf("Text: %s\n", text);
        printf("Options:\n");
        printf("1. Append text\n");
        printf("2. Undo\n");
        printf("3. Redo\n");
        printf("4. Save to file\n");
        printf("5. Load from file\n");
        printf("6. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char newText[MAX_TEXT_LENGTH];
                printf("Enter text to append: ");
                scanf(" %[^\n]s", newText);
                for (int i = 0; i < strlen(newText); i++) {
                    push(&undoStack, text[i]);
                }
                strcat(text, newText);
                break;
            }
            case 2: {
                if (!isEmpty(undoStack)) {
                    char removed = pop(&undoStack);
                    push(&redoStack, text[strlen(text) - 1]);
                    text[strlen(text) - 1] = '\0'; // Remove the last character
                }
                break;
            }
            case 3: {
                if (!isEmpty(redoStack)) {
                    char redoChar = pop(&redoStack);
                    push(&undoStack, redoChar);
                    int len = strlen(text);
                    text[len] = redoChar;
                    text[len + 1] = '\0';
                }
                break;
            }
            case 4: {
                char filename[100];
                printf("Enter the filename to save to: ");
                scanf("%s", filename);
                FILE* file = fopen(filename, "w");
                if (file == NULL) {
                    printf("Error opening the file for writing.\n");
                } else {
                    fprintf(file, "%s", text);
                    fclose(file);
                }
                break;
            }
            case 5: {
                char filename[100];
                printf("Enter the filename to load from: ");
                scanf("%s", filename);
                FILE* file = fopen(filename, "r");
                if (file == NULL) {
                    printf("Error opening the file for reading.\n");
                } else {
                    fgets(text, MAX_TEXT_LENGTH, file);
                    fclose(file);
                }
                break;
            }
            case 6:
                exit(1);
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    textEditor();
    return 0;
}
