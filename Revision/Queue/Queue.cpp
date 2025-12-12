#include <iostream>
#include <queue>
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

class Queue {
    Node* front, * rear;
    public:
        Queue() {
            front = nullptr;
            rear = nullptr;     
        }

        void push(int data) {
            Node* node = new Node(data);
            if(!rear) {
                front = rear = node;
                return;
            }
            rear->next = node;
            rear = node;
        }

        void pop() {
            if(!front) {
                return;
            }

            Node* temp = front;
            front = front->next;
            delete temp;

         if(!front) {
                rear = nullptr;
            }
        }

        bool isEmpty() {
            return front == nullptr;
        }

        int peek() {
            if(!front) return -1;
            return front->data;
        }

        int back() {
            if(!rear) return -1;
            return rear->data;
        }

        int poll() {
            if(!front) {
                return -1;
            }
            int f = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;

            if(!front) {
                rear = nullptr;
            }
            return f;
        }

        void display() {
            if(!front) {
                return;
            }

            Node* temp = front;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.peek() << "\n"; // 10
    cout << "Back: " << q.back() << "\n";  // 30

    q.display(); // 10 20 30

    cout << "Poll: " << q.poll() << "\n"; // removes 10
    q.display(); // 20 30

}