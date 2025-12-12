import java.util.*;

class WeightedGraph  {
    static class Edge {
        int dest, weight;
        Edge(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }
    }

    static class Graph {
        int V;
        LinkedList<Edge>[] adjList;

        Graph(int V) {
            this.V = V;
            adjList = new LinkedList[V];
            for (int i = 0; i < V; i++) adjList[i] = new LinkedList<>();
        }

        void addEdge(int u, int v, int w) {
            adjList[u].add(new Edge(v, w));
            // adjList[v].add(new Edge(u, w)); // Uncomment if undirected
        }

        void printGraph() {
            for (int i = 0; i < V; i++) {
                System.out.print(i + ": ");
                for (Edge e : adjList[i]) {
                    System.out.print("(" + e.dest + "," + e.weight + ") ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(4);
        g.addEdge(0, 1, 5);
        g.addEdge(0, 2, 3);
        g.addEdge(2, 3, 2);

        g.printGraph();
    }
}
