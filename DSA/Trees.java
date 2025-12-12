import java.util.*;

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;

    TreeNode (int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

class Trees {
    TreeNode root;

    public static void preorder(TreeNode node) {
        if (node == null) {
            return;
        }
        System.out.print(node.data + " ");
        preorder(node.left);
        preorder(node.right);
    }

    public static void inorder(TreeNode node) {
        if (node == null) {
            return;
        }
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

    public static List<List<Integer>> levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<List<Integer>> wrapList = new LinkedList<>();

        if (root == null) {
            return wrapList;
        }
        
        queue.offer(root);
        while (!queue.isEmpty()) {
            int levelNum = queue.size();
            List<Integer> subList = new LinkedList<>();
            for (int i = 0; i < levelNum; i++) {
                TreeNode current = queue.poll();
                subList.add(current.data);
                if (current.left != null) queue.offer(current.left);
                if (current.right != null) queue.offer(current.right);
            }
            wrapList.add(subList);
        }
        return wrapList;
    }

    public static void main(String[] args) {
        Trees tree = new Trees();
        tree.root = new TreeNode(1);
        tree.root.left = new TreeNode(2);
        tree.root.right = new TreeNode(3);
        tree.root.left.left = new TreeNode(4);
        tree.root.left.right = new TreeNode(5);
        tree.root.right.right = new TreeNode(6);

        System.out.print("Preorder traversal: ");
        preorder(tree.root);
        System.out.println();

        System.out.print("Inorder traversal: ");
        inorder(tree.root);
        System.out.println();

        System.out.print("LevelOrder traversal: ");
        List<List<Integer>> result = levelOrder(tree.root);
        System.out.println(result);
    }
}
