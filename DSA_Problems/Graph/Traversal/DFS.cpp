#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<int>> adj(N);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    int start;
    cin >> start;

    if (start < 0 || start >= N) {
        cout << "Not found";
        return 0;
    }

    vector<bool> visited(N, false);
    dfs(start, adj, visited);

    return 0;
}
