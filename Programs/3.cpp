#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left, *right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* insert(int arr[], int i, int n) {
    if(i >= n) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = insert(arr, 2*i+1, n);
    root->right = insert(arr, 2*i+2, n);

    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n; cin >> n;
    int arr[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Node* root = insert(arr, 0, n);

    inorder(root);

    return 0;
}