class CLL {
    private class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }
    private Node head = null;
    private Node tail = null;

    // 1️⃣ Insert at Front
    public void insertFront(int data) {
        Node node = new Node(data);
        if (head == null) {
            head = tail = node;
            node.next = head;
        } else {
            node.next = head;
            head = node;
            tail.next = head;
        }
    }

    // 2️⃣ Insert at End
    public void insertEnd(int data) {
        Node node = new Node(data);
        if (head == null) {
            head = tail = node;
            node.next = head;
        } else {
            tail.next = node;
            tail = node;
            tail.next = head;
        }
    }

    // 3️⃣ Insert at Position (1-based index)
    public void insertAtPos(int data, int pos) {
        Node node = new Node(data);
        if (head == null || pos == 1) {
            insertFront(data);
            return;
        }

        Node temp = head;
        for (int i = 1; i < pos - 1 && temp.next != head; i++) {
            temp = temp.next;
        }

        node.next = temp.next;
        temp.next = node;

        if (temp == tail) {
            tail = node;
        }
    }

    // 4️⃣ Delete at Front
    public void deleteFront() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        if (head == tail) {
            head = tail = null;
            return;
        }

        head = head.next;
        tail.next = head;
    }

    // 5️⃣ Delete at End
    public void deleteEnd() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        if (head == tail) {
            head = tail = null;
            return;
        }

        Node temp = head;
        while (temp.next != tail) {
            temp = temp.next;
        }

        temp.next = head;
        tail = temp;
    }

    // 6️⃣ Delete at Position (1-based index)
    public void deleteAtPos(int pos) {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        if (pos == 1) {
            deleteFront();
            return;
        }

        Node temp = head;
        for (int i = 1; i < pos - 1 && temp.next != head; i++) {
            temp = temp.next;
        }

        Node delNode = temp.next;
        temp.next = delNode.next;

        if (delNode == tail) {
            tail = temp;
        }
    }

    // Display
    public void display() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        Node temp = head;
        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);
        System.out.println();
    }
}

public class CircularLinkedList {
    public static void main(String[] args) {
        CLL cll = new CLL();

        // Insertions
        cll.insertEnd(10);
        cll.insertEnd(20);
        cll.insertEnd(30);
        cll.insertEnd(40);
        cll.insertFront(5);
        System.out.println("After insertions:");
        cll.display();

        // Insert at position
        cll.insertAtPos(25, 4);
        System.out.println("After inserting 25 at position 4:");
        cll.display();

        // Deletions
        cll.deleteFront();
        System.out.println("After deleting front:");
        cll.display();

        cll.deleteEnd();
        System.out.println("After deleting end:");
        cll.display();

        cll.deleteAtPos(3);
        System.out.println("After deleting node at position 3:");
        cll.display();
    }
}
