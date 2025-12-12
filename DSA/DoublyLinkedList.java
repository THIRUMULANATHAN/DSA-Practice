
class DLL {
    private class Node {
        int data;
        Node prev;
        Node next;

        Node (int data) {
            this.data = data;
            prev = next = null;
        }
    }

    Node head;
    Node tail;

    DLL() {
        this.head = null;
        this.tail = null;
    }

    public void insertAtFirst(int data) {
        Node node = new Node(data);

        node.next = head;
        if (head != null) {
            head.prev = node;
        }
        head = node;
    }

    public void insert(int data) {
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public void display() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public void displayReverse() {
        Node temp = tail;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }
}

public class DoublyLinkedList {
    public static void main(String [] args) {
        DLL dll = new DLL();
        for (int i=1; i<=5; i++) {
            dll.insert(i);
        }

        dll.insertAtFirst(0);
        dll.display();
        dll.displayReverse();
    }
}