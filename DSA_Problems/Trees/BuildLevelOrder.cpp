#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left,* right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* buildLevelOrderTree(vector<int>& arr) {
    if(arr.empty()) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        if(i < arr.size()) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i < arr.size()) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    if(root->data % 2 != 0) cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Node* root = buildLevelOrderTree(arr);
    inorder(root);

    return 0;
}