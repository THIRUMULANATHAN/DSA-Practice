#include <iostream>
using namespace std;

class Node {
    public:
        pair<int, int> data;
        Node* next;

        Node(int x, int minVal, Node* next = nullptr) {
            this->data = {x,  minVal};
            this->next = nullptr;
        }
};

class Min_Stack {
    Node* head;
    public:
        Min_Stack() {
            this->head = nullptr;
        }

        void insert(int x) {
            if(!head) {
                head = new Node(x, x);
            }
            else {
                int curr_min = min(x, head->data.second);
                head = new Node(x, curr_min, head);
            }
        }

        void pop() {
            if(head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }

        int top() {
            if(head) return head->data.first;
            return -1;
        }

        int minVal() {
            if(head) return head->data.second;
            return -1;
        }
};

int main() {
    int n;
    cin >> n;
    
    int x;
    Min_Stack* min_stack = new Min_Stack();

    while(n) {
        cin >> x;
        min_stack->insert(x);
        n--;
    }

    cout << "Minimum element: " << min_stack->minVal();

    return 0;
}