public class Leetcode143 {

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

    private static ListNode reverseList(ListNode head) {
        ListNode curr = head;
        ListNode next = null;
        ListNode prev = null;

        while(curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    private static void reorderList(ListNode head) {
        if (head == null || head.next == null) return;

        // STEP 1: Find middle (slow will reach mid)
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // STEP 2: Reverse second half
        ListNode second = reverseList(slow.next);
        slow.next = null; // cut first half

        // STEP 3: Merge first half and reversed second half
        ListNode first = head;
        while (first != null && second != null) {
            ListNode temp1 = first.next;
            ListNode temp2 = second.next;

            first.next = second;
            second.next = temp1;

            first = temp1;
            second = temp2;
        }
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
        ListNode l1 = createList(new int[]{1,2,3,4});  

        reorderList(l1);
        printList(l1);
    }
}
