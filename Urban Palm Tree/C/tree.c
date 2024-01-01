#include <stdio.h>

#define MAX_SIZE 10  // Maximum tree size

int tree[MAX_SIZE];

void insert(int data, int index) {
    if(index < MAX_SIZE) {
        tree[index] = data;
    } else {
        printf("Tree is full. Can't insert %d\n", data);
    }
}

void print_tree() {
    for(int i = 0; i < MAX_SIZE; i++) {
        if(tree[i] != 0) {
            printf("Node at index %d: %d\n", i, tree[i]);
        }
    }
}

int main() {
    insert(1, 0);
    insert(2, 1);
    insert(3, 2);
    insert(4, 3);
    insert(5, 4);

    print_tree();

    return 0;
}