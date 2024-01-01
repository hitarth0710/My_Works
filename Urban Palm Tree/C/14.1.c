#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Node {
    int key, data;
    struct Node* next;
} Node;

typedef struct {
    Node* table[SIZE];
} HashTable;

int hash(int key) { return key % SIZE; }

Node* createNode(int key, int data) {
    Node* newNode = malloc(sizeof(Node));
    *newNode = (Node){key, data, NULL};
    return newNode;
}

void insert(HashTable* ht, int key, int data) {
    Node* newNode = createNode(key, data);
    newNode->next = ht->table[hash(key)];
    ht->table[hash(key)] = newNode;
}

Node* search(HashTable* ht, int key) {
    for (Node* temp = ht->table[hash(key)]; temp; temp = temp->next)
        if (temp->key == key) return temp;
    return NULL;
}

void display(HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        for (Node* temp = ht->table[i]; temp; temp = temp->next)
            printf("(%d, %d) ", temp->key, temp->data);
        printf("\n");
    }
}

int main() {
    HashTable ht = {{NULL}};

    insert(&ht, 5, 50);
    insert(&ht, 25, 250);
    insert(&ht, 15, 150);
    insert(&ht, 35, 350);

    printf("Hash Table contents:\n");
    display(&ht);

    int keyToSearch = 15;
    Node* result = search(&ht, keyToSearch);
    printf(result ? "Key %d found. Value: %d\n" : "Key %d not found.\n", keyToSearch, result ? result->data : 0);

    return 0;
}
