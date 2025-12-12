#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

void bfs(char start, map<char, vector<char>> &adjList) {
    map<char, bool> visited;
    queue<char> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << " ";

        // Explore neighbors
        for(char neighbor : adjList[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int e; // number of edges
    cin >> e;

    map<char, vector<char>> adjList;

    for(int i = 0; i < e; i++) {
        char u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // because undirected
    }

    char start;
    cin >> start; // starting node for BFS

    cout << "BFS Traversal: ";
    bfs(start, adjList);

    return 0;
}