import java.util.*;

public class Result1 {
    static class Graph {
        int V;
        LinkedList<Integer> adjList[];
        
        Graph(int V) {
            this.V = V;
            adjList = new LinkedList[V];
            
            for (int i=0; i<V; i++) {
                adjList[i] = new LinkedList<>();
            }
        }
        
        void insert(int u, int v) {
            adjList[u].addFirst(v);
            adjList[v].addFirst(u);
        }
         
        void display(int [] nodes) {
            int sortedNode[] = nodes.clone();
            Arrays.sort(sortedNode);
            for(int node : sortedNode) {
                System.out.print("vertex " + node + ": head");
                
                for (int neighbour : adjList[node]) {
                    System.out.print(" -> " + neighbour);
                }
                System.out.println();
            }
        }
    }
    
    public static void main(String [] args) {
        Scanner scan = new Scanner(System.in);
        
        int node[] = new int[5];
        for (int i=0; i<5; i++) {
            node[i] = scan.nextInt();
        }
        
        Map<Character, Integer> map = new HashMap<>();
        char letter = 'a';
        for (int i=0; i<5; i++) {
            map.put(letter++, node[i]);
        }
        
        Graph g = new Graph(10);
        String edges[] = {"ab", "ae", "bc", "bd", "be", "cd", "de"};
        
        // int edges[][] = {
        //   {0,1},
        //   {0,4},
        //   {1,2},
        //   {1,3},
        //   {1,4},
        //   {2,3},
        //   {3,4}
        // };
        
        // for (int [] edge : edges) {
        //     g.insert(node[edge[0]], node[edge[1]]);
        // }
        
        // g.display(node);
        
        for(String e : edges) {
            int u = map.get(e.charAt(0));
            int v = map.get(e.charAt(1));
            g.insert(u,v);
        }
        g.display(node);
    } 
}