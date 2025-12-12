#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
    
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* head = nullptr, * tail = nullptr;

void enqueue(int data) {
    Node* node = new Node(data);
    if(!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void dequeue(int k) {
    Node* curr = head;
    Node* prev = nullptr;
    while(curr) {
        if(curr->data%k == 0) {
            Node* del = curr;
            if(prev) {
                prev->next = curr->next;
            }
            else {
                head = curr->next;
            }
            if(curr = tail) {
                tail = prev;
            }
            curr = curr->next;
            delete del;
        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
}

void display() {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        enqueue(x);
    }

    int k; cin >> k;
    cout << "Original Queue: ";
    display();
    cout << "\nQueue after selective dequeue: ";
    dequeue(k);
    display();
    
    return 0;
}