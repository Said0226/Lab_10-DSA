#include <iostream>
using namespace std;

// Define the structure of a node for the binary search tree (BST)
struct Node 
{ 
    int data;       // Data stored in the node 
    Node *left;     // Pointer to the left child node 
    Node *right;    // Pointer to the right child node 
}; 

// Function to create a new node 
Node *createNode(int value) 
{ 
    Node *newNode = new Node(); 
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode; 
} 

// Function to insert a node into the BST 
Node *insert(Node *root, int value) 
{ 
    if (root == NULL) 
    { 
        return createNode(value); 
    } 

    if (value < root->data) 
    { 
        root->left = insert(root->left, value); 
    } 
    else if (value > root->data) 
    { 
        root->right = insert(root->right, value); 
    } 

    return root; 
} 

// Function for in-order traversal (Left -> Root -> Right) 
void InOrderTraversal(Node *root) 
{ 
    if (root == NULL) return; 
    InOrderTraversal(root->left);  
    cout << root->data << " ";     
    InOrderTraversal(root->right); 
} 

// Function for pre-order traversal (Root -> Left -> Right) 
void PreOrderTraversal(Node *root) 
{ 
    if (root == NULL) return; 
    cout << root->data << " ";     
    PreOrderTraversal(root->left);  
    PreOrderTraversal(root->right); 
} 

// Function for post-order traversal (Left -> Right -> Root) 
void PostOrderTraversal(Node *root) 
{ 
    if (root == NULL) return; 
    PostOrderTraversal(root->left);  
    PostOrderTraversal(root->right); 
    cout << root->data << " ";       
} 

// Function to delete the entire tree to free memory
void deleteTree(Node* root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root; // Free the current node
    }
}

int main() 
{ 
    Node *root = NULL; 
    int numNodes, value; 

    // Prompt for the number of nodes
    cout << "Enter the number of nodes to insert: "; 
    cin >> numNodes; 

    // Loop to insert each node
    for (int i = 0; i < numNodes; i++) 
    { 
        cout << "Enter value for Node " << (i + 1) << ": "; 
        cin >> value; 
        root = insert(root, value); 
    } 

    // Display the BST using different traversals 
    cout << "\nIn-order Traversal: "; 
    InOrderTraversal(root); 
    cout << endl; 

    cout << "Pre-order Traversal: "; 
    PreOrderTraversal(root); 
    cout << endl; 

    cout << "Post-order Traversal: "; 
    PostOrderTraversal(root); 
    cout << endl; 

    // Clean up memory
    deleteTree(root); 

    return 0; 
} 

