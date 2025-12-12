#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


// CLasiz method

// Time Complexity: O(2 * n) = O(n) where n is the number of nodes in the linked list.
// Auxiliary Space: O(1)


/*
class FindMid {
public:
    Node* head;
    Node* tail;

    FindMid() {
        head = nullptr;
        tail = nullptr;
    }

    int findLen(Node* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        
        return len;
    }

    int midElement(Node* head) {
        int len = findLen(head);
        int mid = (int) len/2;

        Node* temp = head;

        while (mid--) {
            temp = temp->next;
        }
        
        return temp->data;
    }
};

*/

class SlowFastPointer {
public:
    Node* head;
    Node* tail;

    SlowFastPointer() {
        head = nullptr;
        tail = nullptr;
    }

    int midElemnetFinder(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

