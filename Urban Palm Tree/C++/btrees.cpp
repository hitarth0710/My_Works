#include <iostream>
#include <vector>
using namespace std;

class BTreeNode {
    vector<int> keys;
    vector<BTreeNode*> child_ptr;
    bool leaf;
    int min_degree;

public:
    BTreeNode(int _min_degree, bool _leaf);

    void insertNonFull(int k);
    void splitChild(int i, BTreeNode *y);
    void traverse();
    BTreeNode *search(int k);

    friend class BTree;
};

class BTree {
    BTreeNode *root;
    int min_degree;

public:
    BTree(int _min_degree) {
        root = NULL;
        min_degree = _min_degree;
    }

    void traverse() {
        if (root != NULL) root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == NULL) ? NULL : root->search(k);
    }

    void insert(int k);
};

BTreeNode::BTreeNode(int _min_degree, bool _leaf) {
    min_degree = _min_degree;
    leaf = _leaf;
    keys = vector<int>(2 * min_degree - 1);
    child_ptr = vector<BTreeNode*>(2 * min_degree);
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < keys.size(); i++) {
        if (leaf == false && i < child_ptr.size())
            child_ptr[i]->traverse();
        cout << " " << keys[i];
    }

    if (leaf == false && i < child_ptr.size())
        child_ptr[i]->traverse();
}

BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < keys.size() && k > keys[i])
        i++;

    if (i < keys.size() && keys[i] == k)
        return this;

    if (leaf == true)
        return NULL;

    return child_ptr[i]->search(k);
}

void BTree::insert(int k) {
    if (root == NULL) {
        root = new BTreeNode(min_degree, true);
        root->keys[0] = k;
    } else {
        if (root->keys.size() == (2 * min_degree - 1)) {
            BTreeNode *s = new BTreeNode(min_degree, false);

            s->child_ptr[0] = root;

            s->splitChild(0, root);

            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->child_ptr[i]->insertNonFull(k);

            root = s;
        } else
            root->insertNonFull(k);
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = keys.size() - 1;

    if (leaf == true) {
        keys.push_back(k);
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
    } else {
        while (i >= 0 && keys[i] > k)
            i--;

        if (child_ptr[i + 1]->keys.size() == (2 * min_degree - 1)) {
            splitChild(i + 1, child_ptr[i + 1]);

            if (keys[i + 1] < k)
                i++;
        }
        if (i + 1 < child_ptr.size())
            child_ptr[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->min_degree, y->leaf);
    z->keys = vector<int>(min_degree - 1);

    for (int j = 0; j < min_degree - 1; j++)
        z->keys[j] = y->keys[j + min_degree];

    if (y->leaf == false) {
        z->child_ptr = vector<BTreeNode*>(min_degree);
        for (int j = 0; j < min_degree; j++)
            z->child_ptr[j] = y->child_ptr[j + min_degree];
    }

    y->keys.resize(min_degree - 1);

    if (y->leaf == false)
        y->child_ptr.resize(min_degree);

    if (i < child_ptr.size())
        child_ptr.insert(child_ptr.begin() + i + 1, z);

    if (i < keys.size())
        keys.insert(keys.begin() + i, y->keys[min_degree - 1]);
}

int main() {
    int degree, choice, item;
    cout << "Enter the minimum degree of the B-tree: ";
    cin >> degree;
    BTree btree(degree);

    while (1) {
        cout << "\n1.Insert\n2.Search\n3.Traverse\n4.Quit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the item to be inserted: ";
                cin >> item;
                btree.insert(item);
                break;
            case 2:
                cout << "Enter the item to be searched: ";
                cin >> item;
                if (btree.search(item) != NULL)
                    cout << "\nItem found";
                else
                    cout << "\nItem not found";
                break;
            case 3:
                cout << "The B-tree is: ";
                btree.traverse();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
                break;
        }
    }

    return 0;
}