public class Leetcode2 {

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

    private static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l3 = new ListNode(0);
        ListNode head = l3;
        int carry = 0;

        while(l1 != null || l2 != null || carry != 0) {
            int v1 = (l1 != null) ? l1.val : 0;
            int v2 = (l2 != null) ? l2.val : 0;
            int sum = v1 + v2 + carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode temp= new ListNode(digit);
            l3.next = temp;
            l3 = l3.next;
            l1 = (l1 != null) ? l1.next : null;
            l2 = (l2 != null) ? l2.next : null;
        }

        return head.next;
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
        ListNode l1 = createList(new int[]{2, 4, 3});  
        ListNode l2 = createList(new int[]{5, 6, 4});

        ListNode result = addTwoNumbers(l1, l2);

        System.out.print("Result: ");
        printList(result);
    }
}
