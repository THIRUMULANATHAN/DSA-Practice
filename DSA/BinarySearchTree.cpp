#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Insert a value into BST
Node* insertBST(Node* root, int val) {
    if (!root) return new Node(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Build BST from array
Node* buildBST(vector<int>& arr) {
    Node* root = nullptr;
    for (int val : arr) {
        root = insertBST(root, val);
    }
    return root;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Reverse Inorder
void reverseInorder(Node* root) {
    if (!root) return;
    reverseInorder(root->right);
    cout << root->data << " ";
    reverseInorder(root->left);
}

Node* findMin(Node* root) {
    while(root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val) {
    // Base case: empty tree
    if(root == nullptr) {
        return root;
    } 
    
    // Search for the node to delete
    if(val < root->data) {
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data) {
        root->right = deleteNode(root->right, val);
    }
    else {
        // Found the node to delete
        
        // Case 1: Node has no children (leaf node)
        if(root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        
        // Case 2: Node has only right child
        else if(root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // Case 3: Node has only left child
        else if(root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // Case 4: Node has both children
        else {
            // Find inorder successor (minimum in right subtree)
            Node* temp = findMin(root->right);
            
            // Copy successor's data to current node
            root->data = temp->data;
            
            // Delete the successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    Node* root = buildBST(arr);

    cout << "Inorder: ";
    inorder(root);
    cout << "\nReverse Inorder: ";
    reverseInorder(root);
    cout << "\nPreorder: ";
    preOrder(root);
    cout << "\nPostorder: ";
    postOrder(root);
    cout << "\n";

    return 0;
}
