import java.util.*;

class UndirectedGraph {
    static class Graph {
        int V;
        LinkedList<Integer>[] adjList;

        Graph(int V) {
            this.V = V;
            adjList = new LinkedList[V];

            for(int i=0; i<V; i++) {
                adjList[i] = new LinkedList<>();
            } 
        }

        void addEdge(int u, int v) {
            adjList[u].add(v);
            adjList[v].add(u);
        }

        void printGraph() {
            for (int i=0; i<V; i++) {
                System.out.print(i + ": ");
                for (int node : adjList[i]) {
                    System.out.print(node + " ");
                }

                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 3);

        g.printGraph();
    }
}