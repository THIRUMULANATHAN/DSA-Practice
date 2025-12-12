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

Node* buildTree(vector<int>& arr, int i, int n) {
    if (i >= n) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr, 2*i+1, n);
    root->right = buildTree(arr, 2*i+2, n);
    return root;
}

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
    postOrder(root->right);
    cout << root->data << " ";
    postOrder(root->left);
}

//PostOrder -> Reverse_Inorder
void reverseInorder(Node* root) {
    if (!root) return;
    reverseInorder(root->right);
    cout << root->data << " ";
    reverseInorder(root->left);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i<n; i++) cin >> arr[i];

    Node* root = buildTree(arr, 0, n);

    inorder(root);
    cout << "\n";
    reverseInorder(root);

    return 0;
}
