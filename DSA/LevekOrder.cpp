#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
    string data;
    if(!(cin >> data)) return nullptr;
    if(data == "null") return nullptr;
    
    int val = stoi(data);
    Node* root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    
    return root;
}

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    
    queue<Node*>q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i=0; i<size; i++) {
            Node* node = q.front();
            q.pop();
            if(node->left != nullptr) {
                q.push(node->left);
            }
            if(node->right != nullptr) {
                q.push(node->right);
            }
            
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    
    return ans;
}

void printLevelOrder(Node* root) {
    if(!root) {
        cout << "[]";
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    bool first = true;
    
    cout << "[";
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            Node* node = q.front();
            q.pop();
            
            if(!first) cout << ", ";
            cout << node->data;
            first = false;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << ", #";
    }
    cout << "]";
}


int main() {
    Node* root = buildTree();
    printLevelOrder(root);
    return 0;
}