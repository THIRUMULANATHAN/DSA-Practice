#include <iostream>
#include <queue>
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

Node* buildBST(Node* root, int x) {
    if(!root) {
        return new Node(x);
    }

    if(x > root->data) {
        root->right =  buildBST(root->right, x);
    }
    else {
        root->left = buildBST(root->left, x);
    }

    return root;
}

void levelOrderTraversal(Node* root) {
    if(!root) {
        cout << "No elements..";
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        cout << curr->data << " ";
        
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int findlevel(Node* root, int target) {
    int level = 0;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        for(int i=0; i<size; i++) {
            Node* curr = q.front();
            q.pop();

            if(curr->data == target) {
                return level;
            }

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        level++;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int x;
    int target;
    Node* root = nullptr;
    for (int i=0; i<n; i++) {
        cin >> x;
        root = buildBST(root, x);
    }

    cin >> target;
    levelOrderTraversal(root);
    cout << "\n" << findlevel(root, target);

    return 0;
}