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

Node* buildTree() {
    int val;
    cin >> val;

    if(val == -1) {
        return nullptr;
    }

    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

void postOrder(Node* root) {
    if(!root) {
        return;
    }

    cout << root->data << " ";
    postOrder(root->left);
    postOrder(root->right);
}

int main() {
    int n;
    cin >> n;

    Node* root = buildTree();
    postOrder(root);

    return 0;
}