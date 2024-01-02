#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

vector<char>::iterator find(vector<char>::iterator start, vector<char>::iterator end, char value) {
    return find(start, end, value);
}

Node* buildTree(vector<char>::iterator inStart, vector<char>::iterator inEnd, vector<char>::iterator postStart, vector<char>::iterator postEnd) {
    if (inStart == inEnd)
        return NULL;

    char rootValue = *(prev(postEnd));
    auto rootPos = find(inStart, inEnd, rootValue);

    Node* root = new Node;
    root->data = rootValue;
    root->left = buildTree(inStart, rootPos, postStart, next(postStart, distance(inStart, rootPos)));
    root->right = buildTree(next(rootPos), inEnd, next(postStart, distance(inStart, rootPos)), prev(postEnd));

    return root;
}

void preOrder(Node* node) {
    if (node != NULL) {
        cout << node->data << ' ';
        preOrder(node->left);
        preOrder(node->right);
    }
}

void write_dot(Node* node, ofstream& dot_file) {
    if (node != NULL) {
        if (node->left != NULL) {
            dot_file << "    \"" << node->data << "\" -- \"" << node->left->data << "\";\n";
            write_dot(node->left, dot_file);
        }
        if (node->right != NULL) {
            dot_file << "    \"" << node->data << "\" -- \"" << node->right->data << "\";\n";
            write_dot(node->right, dot_file);
        }
    }
}

void generate_dot_file(Node* root, const string& filename) {
    ofstream dot_file(filename);
    dot_file << "graph BST {\n";
    write_dot(root, dot_file);
    dot_file << "}\n";
}


int main() {
    vector<char> inOrder = {'D', 'B', 'H', 'E', 'I', 'A', 'F', 'J', 'C', 'G'};
    vector<char> postOrder = {'D', 'H', 'I', 'E', 'B', 'J', 'F', 'G', 'C', 'A'};
    Node* root = buildTree(inOrder.begin(), inOrder.end(), postOrder.begin(), postOrder.end());

    cout << "Preorder of the constructed tree: ";
    preOrder(root);
    cout << endl;

    generate_dot_file(root, "bstree.dot");


    return 0;
}