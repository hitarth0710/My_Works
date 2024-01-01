#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
struct Node *insert(struct Node *root, const char *ipAddress, char ipClass);
struct Node *search(struct Node *root, const char *ipAddress);
struct Node *deleteNode(struct Node *root, const char *ipAddress);
struct Node *findMinValueNode(struct Node *node);
void inorderTraversal(struct Node *root);

struct Node
{
    char ipAddress[16];
    struct Node *left;
    struct Node *right;
};

// Validation function for IP address
char isValidIPAddress(const char *ipAddress)
{
    int a, b, c, d;
    if (sscanf(ipAddress, "%d.%d.%d.%d", &a, &b, &c, &d) == 4 &&
        a >= 0 && a <= 255 &&
        b >= 0 && b <= 255 &&
        c >= 0 && c <= 255 &&
        d >= 0 && d <= 255)
    {
        // Determine the IP class based on the first octet
        if (a >= 1 && a <= 126)
        {
            return 'A'; // Class A
        }
        else if (a == 127)
        {
            printf("\nLoop back address");
            return 'I';
        }
        else if (a >= 128 && a <= 191)
        {
            return 'B'; // Class B
        }
        else if (a >= 192 && a <= 223)
        {
            return 'C'; // Class C
        }
        else
        {
            return 'D'; // Invalid class
        }
    }
    else
    {
        return 'I'; // Invalid IP address
    }
}

// INSERTION
struct Node *insert(struct Node *root, const char *ipAddress, char ipClass)
{
    if (ipClass == 'I')
    {
        printf("\nInvalid IP Address. Please enter a valid IP Address.\n");
        return root;
    }

    if (root == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        strcpy(newNode->ipAddress, ipAddress);
        newNode->left = newNode->right = NULL;
        printf("\nElement '%s' is inserted with class '%c'...", newNode->ipAddress, ipClass);
        return newNode;
    }

    // Compare the IP address for insertion
    if (strcmp(ipAddress, root->ipAddress) < 0)
    {
        root->left = insert(root->left, ipAddress, ipClass);
    }
    else if (strcmp(ipAddress, root->ipAddress) > 0)
    {
        root->right = insert(root->right, ipAddress, ipClass);
    }
    return root;
}

// SEARCHING
struct Node *search(struct Node *root, const char *ipAddress)
{
    if (root == NULL || strcmp(root->ipAddress, ipAddress) == 0)
    {
        return root;
    }
    // If the IP address to be searched is greater, search in the right subtree
    else if (strcmp(ipAddress, root->ipAddress) > 0)
    {
        return search(root->right, ipAddress);
    }
    // If the IP address to be searched is smaller, search in the left subtree
    else
        return search(root->left, ipAddress);
}

// DEALLOCATION
struct Node *deleteNode(struct Node *root, const char *ipAddress)
{
    if (root != NULL)
    {
        // Find the node to be deleted
        if (strcmp(ipAddress, root->ipAddress) < 0)
        {
            root->left = deleteNode(root->left, ipAddress);
        }
        else if (strcmp(ipAddress, root->ipAddress) > 0)
        {
            root->right = deleteNode(root->right, ipAddress);
        }
        else
        {
            // Node with one child or no child
            if (root->left == NULL)
            {
                struct Node *temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL)
            {
                struct Node *temp = root->left;
                free(root);
                return temp;
            }

            // Node with two children
            struct Node *temp = findMinValueNode(root->right);
            strcpy(root->ipAddress, temp->ipAddress);
            root->right = deleteNode(root->right, temp->ipAddress);

            // The "test" statement is printed here
            printf("test\n");
        }
    }
    return root;
}

// UTILITY FUNCTIONS
struct Node *findMinValueNode(struct Node *node)
{
    struct Node *current = node;

    if (current == NULL)
    {
        printf("Tree is empty.\n");
        return NULL;
    }

    while (current->left != NULL)
    {
        current = current->left;
    }

    // Print the minimum value node
    printf("Minimum Value Node: %s\n", current->ipAddress);

    return current;
}

// DISPLAY
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%s\n", root->ipAddress);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    char ipAddress[20];
    char ipClass;
    int choice;

    do
    {
        printf("\n---------------------------------------------------IP ADDRESS MANAGEMENT SYSTEM---------------------------------------------------\n");
        printf("1. Insert IP Address\n");
        printf("2. Search IP Address\n");
        printf("3. Delete IP Address\n");
        printf("4. Display All IP Addresses\n");
        printf("5. Find Minimum Value Node\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n\nEnter IP Address to insert: ");
            scanf("%s", ipAddress);
            ipClass = isValidIPAddress(ipAddress);
            root = insert(root, ipAddress, ipClass);
            break;

        case 2:
            printf("\n\nEnter IP Address to search: ");
            scanf("%s", ipAddress);
            if (search(root, ipAddress) != NULL)
            {
                printf("IP Address found in the tree.\n");
            }
            else
            {
                printf("IP Address not found in the tree.\n");
            }
            break;

        case 3:
            printf("\n\nEnter IP Address to delete: ");
            scanf("%s", ipAddress);
            root = deleteNode(root, ipAddress);
            break;

        case 4:
            printf("\n\nIP Addresses in the tree:\n");
            inorderTraversal(root);
            break;

        case 5:
            findMinValueNode(root);
            break;

        case 6:
            printf("\n\nExiting program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n\n");
        }
    } while (choice != 6);

    return 0;
}