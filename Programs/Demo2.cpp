#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>>& arr, int start, int V) {
    vector<bool> visited(V+1, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    vector<int> bfs_arr;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        bfs_arr.push_back(curr);

        for(auto it : arr[curr]) {
            if(!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }

    return bfs_arr;
}

vector<vector<int>> getAdjList(int n, int m) {
    vector<vector<int>> adjList(n+1);

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    return adjList;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj = getAdjList(n, m);
    
    for(int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for(int v : adj[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    
    vector<int> bfs_arr = bfs(adj, 1, n);
    
    cout << "\nBFS: ";
    for(auto it : bfs_arr) {
        cout << it << " ";
    }
    
    return 0;
}