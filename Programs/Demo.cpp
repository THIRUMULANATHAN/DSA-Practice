#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Tree node definition
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Simple tree builder
TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < nodes.size() && nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// BFS to find max in each level
vector<int> bfs(TreeNode* root) {
    vector<int> maxElement;
    if (!root) return maxElement;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            maxVal = max(maxVal, node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        maxElement.push_back(maxVal);
    }
    return maxElement;
}

int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    string token;
    vector<string> nodes;

    while (getline(ss, token, ',')) {
        nodes.push_back(token);
    }

    TreeNode* root = buildTree(nodes);
    vector<int> ans = bfs(root);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ", ";
    }
    cout << "]";
    return 0;
}
