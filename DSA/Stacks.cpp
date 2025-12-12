#include <iostream>
using namespace std;
 
class Stacks {
private:
    int size;
    int top;
    int* arr;
public:
    Stacks(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack overflow";
            return;
        }
        cout << arr[top] << "\n";
        top--;
    }

    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << arr[top]<<"\n";
    }

    int etop() {
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

    int csize() {
        return top+1;
    }

    ~Stacks() {
        delete[] arr;
    }
};

int main () {
    int n;
    cin >> n;

    Stacks* s = new Stacks(n);
    int num;
    for (int i=0; i<n; i++) {
        cin >> num;
        s->push(num);
    }

    s->pop();
    s->peek();
    cout << s->empty() << "\n";
    cout << s->csize() << "\n";
}