import java.util.*;

class Node {
    int data;
    Node right;
    Node left;

    Node(int data) {
        this.data = data;
        this.right = null;
        this.left = null;
    }
}

class Main {
    private static Node buildTree(List<String> arr, int i, int n) {
        if (i >= n || arr.get(i).equals("null")) return null;
        Node root = new Node(Integer.parseInt(arr.get(i)));
        root.left = buildTree(arr, 2 * i + 1, n);
        root.right = buildTree(arr, 2 * i + 2, n);
        return root;
    }

    private static Node prev = null;

    private static void flatten(Node root) {
        if (root == null) return;

        flatten(root.right);
        flatten(root.left);

        root.right = prev;
        root.left = null;
        prev = root;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String input = scan.nextLine().trim();

        if (input.length() <= 2 || input.equals("[]")) {
            System.out.println("[]");
            scan.close();
            return;
        }

        input = input.substring(1, input.length() - 1); // remove [ ]
        String parts[] = input.split(",");

        List<String> li = new ArrayList<>();
        for (String p : parts) {
            li.add(p.trim());
        }

        Node root = buildTree(li, 0, li.size());

        flatten(root);

        // Print flattened linked list in expected format
        Node curr = root;
        System.out.print("[");
        while (curr != null) {
            System.out.print(curr.data);
            if (curr.right != null) {
                System.out.print(",null,");
            }
            curr = curr.right;
        }
        System.out.println("]");

        scan.close();
    }
}
