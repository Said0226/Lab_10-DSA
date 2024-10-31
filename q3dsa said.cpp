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

bool search(Node* root, int value) {
    if (root == NULL) {
        return false; 
    }
    if (value == root->data) {
        return true; 
    } else if (value < root->data) {
        return search(root->left, value); 
    } else {
        return search(root->right, value); 
    }
}

int main() {
    Node* root = NULL;
    int value;
    char choice;

    do {
        cout << "Enter a value to insert into the BST: ";
        cin >> value;
        root = insert(root, value);

        cout << "Do you want to insert another value? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    
    cout << "Enter a value to search in the BST: ";
    cin >> value;
    if (search(root, value)) {
        cout << "Value " << value << " found in the BST." << endl;
    } else {
        cout << "Value " << value << " not found in the BST." << endl;
    }

    return 0;
}

