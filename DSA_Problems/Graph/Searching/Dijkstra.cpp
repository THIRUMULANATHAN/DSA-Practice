#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// Build the undirected weighted graph
void buildGraph(vector<pair<int, int>> adj[], int E) {
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected
    }
}

// Perform Dijkstra’s algorithm
void dijkstra(int V, vector<pair<int, int>> adj[], int src, vector<int>& dist, vector<int>& parent) {
    dist.assign(V, INT_MAX);
    parent.assign(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto &edge : adj[node]) {
            int adjNode = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[adjNode]) {
                dist[adjNode] = dist[node] + weight;
                parent[adjNode] = node;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
}

// Print shortest path or -1 if unreachable
void printShortestPath(int src, int dest, const vector<int>& dist, const vector<int>& parent) {
    if (dist[dest] == INT_MAX) {
        cout << -1;
        return;
    }

    cout << dist[dest] << endl;

    vector<int> path;
    for (int i = dest; i != -1; i = parent[i])
        path.push_back(i);

    reverse(path.begin(), path.end());
    for (int city : path)
        cout << city << " ";
    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> adj[V];
    buildGraph(adj, E);

    int src, dest;
    cin >> src >> dest;

    vector<int> dist, parent;

    dijkstra(V, adj, src, dist, parent);
    printShortestPath(src, dest, dist, parent);

    return 0;
}
