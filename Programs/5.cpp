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

Node* insert(Node* root, int x) {
    if(!root) return new Node(x);
    if(root->data > x) root->left = insert(root->left, x);
    if(root->data < x) root->right = insert(root->right, x);

    return root;
}

Node* findMin(Node* root) {
    while(root->left) {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int data) {
    if(!root) {
        return root;
    }

    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if(!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        else if(!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

bool isPresent(Node* root, int x) {
    if(root->data == x) return true;

    if(root->data > x) {
        isPresent(root->right, x);
    }
    if(root->data < x) {
        isPresent(root->left, x);
    }

    return false;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n, x; cin >> n;
    Node* root = nullptr;
    for(int i=0; i<n; i++) {
        cin >> x;
        root = insert(root, x);
    }

    int k; cin >> k;
    // if(isPresent(root, k)) {
    //     cout << "Found";
    // }
    // else {
    //     cout << "Not found";
    // }

    cout << "Before: " ;
    inorder(root);
    cout << "\nAfter: ";
    Node* after = deleteNode(root, k);
    inorder(after);
    return 0;
}