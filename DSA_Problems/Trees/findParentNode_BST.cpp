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

Node* buildBST(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }
    
    if(val > root->data) {
        root->right = buildBST(root->right, val);
    }
    if(val < root->data) {
        root->left = buildBST(root->left, val);
    }
    
    return root;
}

Node* findLCA(Node* root, int n1, int n2) {
    if(!root) {
        return nullptr;
    }
    
    if(root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }
    
    if(root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }
    
    return root;
}

int main() {
    int n;
    cin >> n;
    
    Node* root = nullptr;
    int val;
    for (int i=0; i<n; i++) {
        cin >> val;
        root = buildBST(root, val);
    }
    
    int n1,n2;
    cin >> n1 >> n2;
    
    Node* ans = findLCA(root, n1, n2);
    
    cout << ans->data;
}