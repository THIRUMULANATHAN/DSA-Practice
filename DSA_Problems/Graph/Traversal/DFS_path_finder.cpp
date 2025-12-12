#include <iostream>
#include <vector>
using namespace std;

void pathFinder(vector<vector<int>>& adj, int u, int d, vector<bool>& visited, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if(u == d) {
        for(int i=0; i<path.size(); i++) {
            cout << path[i] << (i == path.size()-1 ? "\n" : " ");
        }
    }
    else {
        for (int v : adj[u]) {
            if(!visited[v]) {
                pathFinder(adj, v, d, visited, path);
            }
        }
    }

    path.pop_back();
    visited[u] = false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {   // ✅ use m
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int s,e;
    cin >> s >> e;
    vector<bool> visited(n, false);
    vector<int> path;

    pathFinder(adj, s, e, visited, path);

    return 0;
}


/*
4 6
0 1
0 2
0 3
2 0
2 1
1 3
2 3
*/