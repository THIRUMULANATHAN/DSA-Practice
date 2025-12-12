#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data=data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* buildTree(vector<int>& arr, int i, int n) {
    if(i >= n) {
        return nullptr;
    }

    Node* root = new Node(arr[i]);
    root->left = buildTree(arr, 2*i+1, n);
    root->right = buildTree(arr, 2*i+2, n);

    return root;
}

int sumOfNodes(Node* root) {
    if(!root) {
        return 0;
    }

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    int n;
    vector<int> arr;
    while(cin >> n) {
        arr.push_back(n);
    }

    Node* root = buildTree(arr, 0, arr.size());
    cout << sumOfNodes(root);

    return 0;
}