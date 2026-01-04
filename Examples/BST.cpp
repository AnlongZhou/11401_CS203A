#include <iostream>
using namespace std;

// ==========================================
// Binary Search Tree (BST)
// ==========================================
struct BSTNode {
    int data;
    BSTNode *left, *right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST {
  private:
    BSTNode *root;

    BSTNode *insertRec(BSTNode *node, int data) {
        if (!node)
            return new BSTNode(data);

        if (data < node->data)
            node->left = insertRec(node->left, data);
        else if (data > node->data)
            node->right = insertRec(node->right, data);

        return node;
    }

    bool searchRec(BSTNode *node, int key) {
        if (!node)
            return false;
        if (node->data == key)
            return true;

        if (key < node->data)
            return searchRec(node->left, key);
        else
            return searchRec(node->right, key);
    }

    void inorderRec(BSTNode *node) {
        if (!node)
            return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

  public:
    BST() : root(nullptr) {}

    void insert(int data) { root = insertRec(root, data); }

    bool search(int key) { return searchRec(root, key); }

    void display() {
        inorderRec(root);
        cout << endl;
    }
};
