#include <iostream>
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

Node* buildTree(Node* root, int data) {
    if(!root) {
        return new Node(data);
    }
    
    if(data < root->data)
        root->left = buildTree(root->left, data);
    else
        root->right = buildTree(root->right, data);
    
    return root;
}

int checkHeight(Node* root) {
    if(!root) {
        return 0;
    }
    
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1) 
        return -1;
        
    if(abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node* root) {
    return checkHeight(root) != -1;
}


int main() {
    int n;
    cin >> n;
    
    int val;
    Node* root = nullptr;
    while(n) {
        cin >> val;
        root =  buildTree(root, val);
        n--;
    }
    
    if (isBalanced(root)) {
        cout << "The binary tree is height-balanced";
    }
    else {
        cout << "The binary tree is not height-balanced";
    }
    
    return 0;
}