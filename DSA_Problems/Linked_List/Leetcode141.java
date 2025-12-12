public class Leetcode141 {

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

    private static boolean hasCycle(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if(slow == fast) return true;
        }
        return false;
    }

    private static ListNode tail = null;
    
    private static void createCycle(ListNode head, int pos) {
        if(pos < 0) return;
        ListNode temp = head;
        while(temp.next != null) temp = temp.next;
        tail = temp;
        temp = head;
        for(int i=0; i<pos; i++) {
            temp = temp.next;
        }
        tail.next = temp;
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
        ListNode l1 = createList(new int[]{3,2,0,-4});  
        int pos = 1;
        createCycle(l1, pos);
        Boolean ans = hasCycle(l1);
        System.out.println(ans);
    }
}
