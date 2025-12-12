#include <iostream>
using namespace std;

// Node structure
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

// Insert into BST
Node* buildBST(Node* root, int val) {
    if(!root) {
        return new Node(val);
    }

    if(val < root->data)
        root->left = buildBST(root->left, val);
    else if(val > root->data)
        root->right = buildBST(root->right, val);

    return root;
}

// Compute total sum and count of nodes
void computeSumAndCount(Node* root, int & sum, int & count) {
    if(!root) return;
    sum += root->data;
    count++;
    computeSumAndCount(root->left, sum, count);
    computeSumAndCount(root->right, sum, count);
}

// Find minimum node in BST
int getMin(Node* root) {
    while(root->left) {
        root = root->left;
    }
    return root->data;
}

// Delete a node from BST
Node* deleteNode(Node* root, int target) {
    if(!root) return nullptr;

    if(target < root->data) {
        root->left = deleteNode(root->left, target);
    }
    else if(target > root->data) {
        root->right = deleteNode(root->right, target);
    }
    else {
        // Node found
        if(!root->left) {
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
            // Two children: replace with inorder successor
            root->data = getMin(root->right);
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Remove nodes >= average
Node* removeAboveAverage(Node* root, double avg) {
    if(!root) {
        return nullptr;
    }

    root->left = removeAboveAverage(root->left, avg);
    root->right = removeAboveAverage(root->right, avg);

    // Keep deleting while root->data >= avg
    while(root && root->data >= avg) {
        root = deleteNode(root, root->data);
    }

    return root;
}


int main() {
    Node* root = nullptr;
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = buildBST(root, x);
    }

    // Step 1: Compute average
    int sum = 0, count = 0;
    computeSumAndCount(root, sum, count);
    double avg = (double)sum / count;

    // Step 2: Remove nodes >= average
    root = removeAboveAverage(root, avg);

    // Step 3: Print result
    cout << "Inorder Traversal after removal: ";
    inorder(root);
    cout << endl;

    return 0;
}
