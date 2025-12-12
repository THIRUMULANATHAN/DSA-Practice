/*
Input 1 : 56,null,85,90,null,null
Output 1 : [56, 85]

Input 2 : 1,3,2,5,3,null,9
Output 2 : [1, 3, 9] 

Input 3 : 10,20,30,40,50
Output 3 : [10, 30, 50]
*/


#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
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

Node* buildTree(vector<string>& val) {
    if(!val.empty() && val[0] == "null") {
        return nullptr;
    }

    Node* root = new Node(stoi(val[0]));
    queue<Node*> q;
    q.push(root);
    int i=1;
    
    while(!q.empty() && i<val.size()) {
        Node* curr = q.front();
        q.pop();
        
        if(val[i] != "null") {
            curr->left = new Node(stoi(val[i]));
            q.push(curr->left);
        }
        i++;

        if (i >= val.size()) break;

        if(val[i] != "null") {
            curr->right = new Node(stoi(val[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

vector<int> largestValues(Node* root) {
    vector<int> res;
    if (!root) return res;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        int maxVal = INT_MIN;

        for (int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();
            maxVal = max(maxVal, curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        res.push_back(maxVal);
    }

    return res;
}

vector<string> split(const string& s, char delimeter) {
    vector<string> tokens;
    string token;
    istringstream ss(s);

    while (getline(ss, token, delimeter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string s;
    getline(cin, s);

    vector<string> values = split(s, ',');
    Node* root = buildTree(values);

    vector<int> res = largestValues(root);

    cout << "[";
    for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << ", ";
        cout << res[i];
    }
    cout << "]";

    return 0;
}