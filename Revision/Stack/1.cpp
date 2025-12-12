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

Node* top = nullptr;

void insert(int data) {
    Node* node = new Node(data);
    node->next = top;
    top = node;
    
    cout << "Pushed: " << top->data << "\n";
}

void display() {
    Node* temp = top;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void pop() {
    cout << "Popping: " << top->data << "\n";
    top = top->next;
}

void peek() {
    cout << "Top: " << top->data << "\n";
}

bool isEmpty() {
    return top == nullptr;
}

int main() {
    int choice;
    
    while(true) {
        cin >> choice;
        switch(choice) {
            case 1:
                int data;
                cin >> data;
                insert(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Is Enmpty: " << isEmpty() << "\n";
                break;
            case 5:
                peek();
                break;
            case 6:
                cout << "Exiting..\n";
                return 0;
            default:
                cout << "Invalid choice\n";
                break;
                
        }
    }   
}