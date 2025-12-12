import java.util.Scanner;

// Node class

// BinaryTree class
class BinaryTree {
    private class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
        }
    }

    Node root;

    public void buildFromArray(int[] arr) {
        int n = arr.length;
        Node[] nodes = new Node[n];

        // Create all nodes
        for (int i = 0; i < n; i++)
            nodes[i] = new Node(arr[i]);

        // Link children using 2*i+1 and 2*i+2 rule
        for (int i = 0; i < n; i++) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n)
                nodes[i].left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i].right = nodes[rightIndex];
        }

        root = nodes[0]; // First element is root
    }

    public void preorder(Node node) {
        if (node == null) return;
        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    public int sum(Node node) {
        if (node == null) return 0;
        return node.data + sum(node.left) + sum(node.right);
    }
}

// Main class
public class TreeFromArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();              // number of elements
        int[] arr = new int[n];            // array of node values

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        BinaryTree tree = new BinaryTree();
        tree.buildFromArray(arr);

        System.out.print("Preorder: ");
        tree.preorder(tree.root);

        System.out.println("\nSum: " + tree.sum(tree.root));
        sc.close();
    }
}
