#include <stdio.h>
#include <stdlib.h>

struct bst {
  int data;
  struct bst* left;
  struct bst* right;
};

struct bst* createnode(int data) {
  struct bst* newnode = malloc(sizeof(struct bst));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

struct bst* insert(struct bst* root, int data) {
  if (!root) {
    return createnode(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }

  return root;
}

void display(struct bst* root) {
  if (!root) {
    return;
  }
    display(root->left);
    printf("%d ", root->data);
  
  display(root->right);
}

int main() {
  struct bst* root = NULL;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 60);
  insert(root, 70);
  insert(root, 80);
  insert(root, 20);

  display(root); // Added display function call

  return 0;
}
