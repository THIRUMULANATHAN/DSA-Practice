#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

bool bfsShortestPath(vector<vector<int>> & adj, vector<int> & parent, int source, int goal) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    visited[source] = true;
    parent[source] = -1;
    q.push(source);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        if(node == goal) return true;

        for(int i=0; i<n; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = node;
                q.push(i);
            }
        }
    }

    return false;
}

stack<int> constructPath(int src, int goal, vector<int> parent) {
    stack<int> path;
    int curr = goal;

    while(curr != -1) {
        path.push(curr);
        curr = parent[curr];
    }
    return path;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj_mat(n, vector<int>(n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> adj_mat[i][j];
        }
    }

    int src, goal;
    cin >> src >> goal;

    if (src < 0 || src >= n || goal < 0 || goal >= n) {
        cout << "Not found" << endl;
        return 0;
    }

    vector<int> parent(n, -1);

    bool found = bfsShortestPath(adj_mat, parent, src, goal);
    if(!found) {
        cout << "Not found" << endl;
        return 0;
    }

    stack<int> path = constructPath(src, goal, parent);
    cout << path.size()-1 << "\n";
    while (!path.empty()) {
        cout << path.top() << (path.size() == 1 ? "\n" : " ");
        path.pop();
    }

    return 0;
}

/*
Sample test case 1:
5 -> N
adj-matrix:
0 1 1 0 0   
1 0 1 0 0
1 1 0 1 0
0 0 1 0 1
0 0 0 1 0
source, target
0 4

Sample test case 1:
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
0 4
*/