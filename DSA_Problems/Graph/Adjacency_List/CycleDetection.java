import java.util.*;

public class CycleDetection {
    static boolean dfs(int node, boolean[] visited, boolean[] recStack, LinkedList<Integer>[] adjList) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor] && dfs(neighbor, visited, recStack, adjList)) return true;
            else if (recStack[neighbor]) return true;
        }

        recStack[node] = false;
        return false;
    }

    public static void main(String[] args) {
        int V = 4;
        LinkedList<Integer>[] adjList = new LinkedList[V];
        for (int i = 0; i < V; i++) adjList[i] = new LinkedList<>();

        adjList[0].add(1);
        adjList[1].add(2);
        adjList[2].add(0); // cycle here
        adjList[2].add(3);

        boolean[] visited = new boolean[V];
        boolean[] recStack = new boolean[V];
        boolean hasCycle = false;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfs(i, visited, recStack, adjList)) {
                hasCycle = true;
                break;
            }
        }

        System.out.println("Graph contains cycle? " + hasCycle);
    }
}
