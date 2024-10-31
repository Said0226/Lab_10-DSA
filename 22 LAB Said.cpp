#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;  
    return newNode;  
}

Node* insert(Node* root, int value) {
    if (root == NULL) { 
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void InOrderTraversal(Node* root) {
    if (root == NULL) return;  
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* root) {
    if (root == NULL) return;  
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root) {
    if (root == NULL) return;  
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "In-Order traversal of the BST: ";
    InOrderTraversal(root);
    cout << endl;

    cout << "Pre-Order traversal of the BST: ";
    PreOrderTraversal(root);
    cout << endl;

    cout << "Post-Order traversal of the BST: ";
    PostOrderTraversal(root);
    cout << endl;

    return 0;
}

