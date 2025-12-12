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

class Queue {
    Node* front, * rear; 
    public:
        Queue() {
            this->front = nullptr;
            this->rear = nullptr;
        }

        void enque(int data) {
            Node* node = new Node(data);
            
            if(!rear) {
                front = node;
                rear = node;
                return;
            }
            rear->next = node;
            rear = node;
        }

        void deque() {
            if(front == nullptr) {
                cout << "Queue is empty.\n";
                return;
            }

            Node* temp = front;
            front = front->next;
            delete(temp);

            if(front == nullptr) {
                rear = nullptr;
            }
        }

        int peek() {
            if(front == nullptr) {
                cout << "Queue is empty.\n";
                return -1;
            }
            return front->data;
        }

        void display() {
            Node* temp = front;
            while(temp) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n";
        }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int num;
    Queue* q = new Queue();
    cout << "Enter " << n << " elements:\n";
    for (int i=0; i<n; i++) {
        cin >> num;
        q->enque(num);
    }

    cout << "Elements are: ";
    q->display();
    cout << "Peeked: " << q->peek() << "\n";
    return 0;
}
