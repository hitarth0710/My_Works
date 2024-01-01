#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *getnode(int );
struct node *insert(struct node* , int );


int main()
{
    return 0;
}

struct node *getnode(int data)
{
    struct node *ptr;
    ptr = new node;
    if(!ptr){
        cout<<"Error"<<endl;
        return nullptr;
    }
    ptr->data = data;
    ptr->left = ptr->right = nullptr;
    return ptr;
}

struct node *insert(struct node* root, int data)
{
    if(root == nullptr){
        root = getnode(data);
    }    
    else if(data <= root->data)
    {
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}