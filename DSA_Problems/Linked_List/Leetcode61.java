public class Leetcode61 {

    private static class ListNode {
        int val;
        ListNode next;

        ListNode() {}

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    private static ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;

        ListNode tail = head;
        int len = 1;
        while (tail.next != null) {
            tail = tail.next;
            len++;
        }

        k = k%len;
        if(k == 0) return head;

        tail.next = head;
        int steps = len-k-1;
        ListNode newTail = head;
        for(int i=0; i<steps; i++) {
            newTail = newTail.next;
        }

        ListNode newHead  = newTail.next;
        newTail.next = null;

        return newHead;
    }

    private static ListNode createList(int[] nums) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;

        for (int n : nums) {
            curr.next = new ListNode(n);
            curr = curr.next;
        }
        return dummy.next;
    }


    private static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) System.out.print(" -> ");
            head = head.next;
        }
        System.out.println();
    }


    public static void main(String[] args) {
        ListNode l1 = createList(new int[]{1,2,3,4,5});  
        int k = 2;
        ListNode ans = rotateRight(l1,2);
        printList(ans);
    }
}
