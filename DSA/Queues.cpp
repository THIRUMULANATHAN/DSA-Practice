#include <iostream>
#include <queue>
using namespace std;

class Queues {
    int* arr;
    int f;
    int r;
    int size;
public:
    Queues (int size) {
        this->size = size;
        arr = new int[size];
        f = -1;
        r = -1;
    }

    void enqueue(int data) {
        if (r == size-1) {
            cout << "Queue is full \n ";
        }
        else if (r == -1 && f == -1) {
            r = 0, f = 0;
            arr[r] = data;
        }
        else {
            r++;
            arr[r] = data;
        }
    }

    void display() {
        for (int i=f; i<=r; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void deque() {
        if (r == -1 && f == -1) {
            cout << "No elements present \n";
        }
        else if (r == f) {
            cout << "Popped: " << arr[f] << "\n";
            r = -1, f = -1;
        }
        else {
            cout << "Popped: " << arr[f] << "\n";
            f++;
        }
    }

    void front() {
        cout << arr[f];
    }

    bool empty() {
        if (r == -1 && f == -1) {
            return true;
        }
     return false;
    }
};

int main () {
    int size; cin >> size;
    Queues* q = new Queues(size);
    int num;

    for (int i=0; i<size; i++) {
        cin >> num;
        q->enqueue(num);
    }

    q->display();
    q->deque();
    q->deque();

    q->display();
    cout << q->empty();
}