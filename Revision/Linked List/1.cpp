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

Node* buildTree(vector<int>& nums, int i, int n) {
    if(i>=n) {
        return nullptr;
    }

    Node* root = new Node(nums[i]);
    root->left = buildTree(nums, 2*i+1, n);
    root->right = buildTree(nums, 2*i+2, n);
    
    return root;
}

Node* buildBST(Node* root, int val) {
    if(!root) {
        return new Node(val);
    }
    
    if(root->data > val) {
        root->left = buildBST(root->left, val);
    }
    if(root->data < val) {
        root->right = buildBST(root->right, val);
    }

    return root;
}

void preorder(Node* root) {
    if(!root) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int sumOfNodes(Node* root) {
    if(!root) {
        return 0;
    }

    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}
 
int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    Node* root1 = buildTree(arr, 0, n);
    preorder(root1);


    cout << "\n\n";

    
    int m;
    cin >> m;
    Node* root2 = nullptr;
    int x;
    for(int i=0; i<m; i++) {
        cin >> x;
        root2 = buildBST(root2, x);
    }

    preorder(root2);
 
    return 0;
} 