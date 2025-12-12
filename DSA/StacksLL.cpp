#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int data) {
       this->data = data;
       this->next = nullptr; 
    }
};

class StackLL {
private:
    Node* top;
public:
    StackLL() {
        top = nullptr;
    }
    void push(int data) {
        Node* node = new Node(data);
        node->next = top;
        top = node;
    }
    void peek() {
        if (top) {
            cout << top->data;
        }
        else {
            cout << "Stack is empty";
            return;
        }
    }
    void pop() {
        if (!top) {
            cout << "Stack is empty";
            return;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display() {
        if (!top) {
            cout << "Stack is empty";
            return;
        }
        else {
            Node* temp = top;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }
}; 

int main () {
    StackLL stackll;
    
    for (int i=1; i<5; i++) {
        stackll.push(i);
    }
    stackll.peek();
    cout << "\n-----\n";
    stackll.pop();
    stackll.display();
}