#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
    int sz;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
        sz = 0;
    }

    int size() { return sz; }

    void insertAtFirst(int data) {
        Node* node = new Node(data);
        if(!head) head = tail = node;
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        sz++;
    }

    void insertAtEnd(int data) {
        Node* node = new Node(data);
        if(!head) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        sz++;
    }

    void insertAt(int data, int pos) {
        if(pos <= 1) { insertAtFirst(data); return; }
        if(pos > sz) { insertAtEnd(data); return; }

        Node* temp = head;
        for(int i=1; i<pos-1; i++) temp = temp->next;

        Node* node = new Node(data);
        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
        sz++;
    }

    void removeFirst() {
        if(!head) return;
        Node* temp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        sz--;
    }

    void removeLast() {
        if(!head) return;
        if(head == tail) { delete head; head = tail = nullptr; sz--; return; }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        sz--;
    }

    void removeAt(int pos) {
        if(pos <= 1) { removeFirst(); return; }
        if(pos >= sz) { removeLast(); return; }

        Node* temp = head;
        for(int i=1; i<pos; i++) temp = temp->next;

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        sz--;
    }

    void display() {
        Node* temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void displayReverse() {
        Node* temp = tail;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "\n";
    }

    void removeDuplicates() {
        unordered_set<int> seen;
        Node* temp = head;

        while(temp) {
            Node* nextNode = temp->next;  // store next node

            if(seen.count(temp->data)) {  // if already seen, delete temp
                // Fix links
                if(temp->prev) temp->prev->next = temp->next;
                if(temp->next) temp->next->prev = temp->prev;

                // Update head/tail
                if(temp == head) head = temp->next;
                if(temp == tail) tail = temp->prev;

                delete temp;
            } else {
                seen.insert(temp->data);    // mark as seen
            }

            temp = nextNode;  // move to next node
        }
    }

};

int main() {
    int n;
    cin >> n;
    DoublyLinkedList dll;

    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        dll.insertAtEnd(x);
    }

    dll.insertAt(8, 3);   // insert 8 at position 3
    dll.display();
    dll.displayReverse();

    return 0;
}
