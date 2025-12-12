// public class Main {
//     public static void main(String[] args) {
//         System.out.println(reverse("Hello World"));
//         System.out.println(isPalindrome("racecar"));
//         System.out.println(decimalToBinary(245, ""));
//         System.out.println(sumOfN(10));

//         int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//         System.out.println(binarySearch(arr, 0, arr.length, 6));
//     }
    
//     private static String reverse(String input) {
//         if (input == "") {
//             return "";
//         }

//         return reverse(input.substring(1)) + input.charAt(0);
//     }

//     private static boolean isPalindrome(String input) {
//         if (input.length() == 0 || input.length() == 1) {
//             return true;
//         }

//         if (input.charAt(0) == input.charAt(input.length()-1)) {
//             return isPalindrome(input.substring(1, input.length()-1));
//         }

//         return false;
//    }

//     private static int sumOfN(int n) {
//         if (n <= 1) {
//             return n;
//         }

//         return n + sumOfN(n-1);
//     }

//     private static String decimalToBinary(int num, String result) {
//         if (num == 0) {
//             return result;
//         }

//         result = num % 2 + result;

//         return decimalToBinary(num/2, result);
//     }

//     private static int binarySearch(int arr[], int left, int right, int target) {
//         if (left > right) {
//             return -1;
//         }

//         int mid = (left + right) / 2;

//         if (target == arr[mid]) {
//             return mid;
//         }

//         if (target < arr[mid]) {
//             return binarySearch(arr, left, mid-1, target);
//         }

//         return binarySearch(arr, mid+1, right, target);
//     }

    
// }

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();
        int n = sc.nextInt(); // number of row conditions
        int[][] rowCond = new int[n][2];
        for (int i = 0; i < n; i++) {
            rowCond[i][0] = sc.nextInt();
            rowCond[i][1] = sc.nextInt();
        }

        int m = sc.nextInt(); // number of col conditions
        int[][] colCond = new int[m][2];
        for (int i = 0; i < m; i++) {
            colCond[i][0] = sc.nextInt();
            colCond[i][1] = sc.nextInt();
        }

        int[] rowOrder = topoSort(k, rowCond);
        int[] colOrder = topoSort(k, colCond);

        if (rowOrder == null || colOrder == null) {
            System.out.println("No matrix satisfies the conditions.");
            sc.close();
            return;
        }

        int[][] matrix = new int[k][k];
        int[] rowPos = new int[k + 1];
        int[] colPos = new int[k + 1];

        for (int i = 0; i < k; i++) {
            rowPos[rowOrder[i]] = i;
            colPos[colOrder[i]] = i;
        }

        for (int num = 1; num <= k; num++) {
            matrix[rowPos[num]][colPos[num]] = num;
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                System.out.print(matrix[i][j]);
                if (j != k - 1) System.out.print(" ");
            }
            System.out.println();
            sc.close();
        }
    }

    static int[] topoSort(int k, int[][] cond) {
        List<List<Integer>> graph = new ArrayList<>();
        int[] indegree = new int[k + 1];

        for (int i = 0; i <= k; i++) graph.add(new ArrayList<>());

        for (int[] c : cond) {
            graph.get(c[0]).add(c[1]);
            indegree[c[1]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) q.add(i);
        }

        int[] order = new int[k];
        int idx = 0;

        while (!q.isEmpty()) {
            int u = q.poll();
            order[idx++] = u;
            for (int v : graph.get(u)) {
                indegree[v]--;
                if (indegree[v] == 0) q.add(v);
            }
        }

        if (idx != k) return null; // cycle exists
        return order;
    }
}