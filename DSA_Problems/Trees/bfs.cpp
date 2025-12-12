#include <iostream>
#include <queue>
#include <stack>

class Node {
    public:
        int data;
        Node* left, * right;

        Node(int data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};

Node* buildTree(std :: vector<int> &arr, int i, int n) {
    if(i >= n) {
        return nullptr;
    }

    Node* root = new Node(arr[i]);
    root->left = buildTree(arr, 2*i+1, n);
    root->right = buildTree(arr, 2*i+2, n);
    return root;
}

void bfs(Node* root) {
    if (!root) return;

   std :: queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

       std :: cout << curr->data << " "; 

        if (curr->left)  q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

void rev_bfs(Node* root) {
    if(!root) {
        return;
    }

    std ::  queue<Node*> q;
    std :: stack<int> s;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        s.push(curr->data);

        if (curr->right) q.push(curr->right);
        if (curr->left) q.push(curr->left);
    }

    while(!s.empty()) {
        std :: cout << s.top() << " ";
        s.pop();
    }
}

void inorder(Node* root) {
    if(!root) {
        return;
    }

    inorder(root->left);
    std :: cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    std :: cin >> n;
    std :: vector<int> arr(n);
    for(int i=0; i<n; i++) {
        std :: cin >> arr[i];
    } 
    
    Node* root = buildTree(arr, 0, n);
    Node* root1 = root;
    inorder(root);
    std :: cout << "\n";
    rev_bfs(root1);

    return 0;
}