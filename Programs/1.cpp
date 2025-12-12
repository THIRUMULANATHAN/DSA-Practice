#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int data) {
            this->data = data;
            this->right = nullptr;
            this->left = nullptr;
        }
};

Node* buildTree(vector<int>& arr, int idx, int n) {
    if(idx >= n) {
        return nullptr;
    }
    
    Node* root = new Node(arr[idx]);
    root->left = buildTree(arr, 2*idx+1, n);
    root->right = buildTree(arr, 2*idx+2, n);
    
    return root;
}

void inOrder(Node* root, vector<int>& arr) {
    if(!root) {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

int main() {
    int n;
    cin >> n;
    
    vector<int>arr(n);
    int x;
    
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    Node* root = buildTree(arr, 0, n);
    
    vector<int> il;
    inOrder(root, il);
    
    unordered_map<int, int> idxMap;
    for (int i=0; i<il.size(); i++) {
        idxMap[il[i]] = i;
    }
    
    for (int v : arr) {
        int idx = idxMap[v];
        int prev = (idx > 0) ? il[idx - 1] : 0;
        int suc = (idx < il.size()-1) ? il[idx+1] : 0;
        cout << v << " : "  << prev << "," << suc << "\n";  
    }
    
    return 0;
}