#include <iostream>
#include <deque>

using namespace std;

int main () {
    deque<int> dq;
    
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_front(5);
    dq.push_back(6);
    dq.push_back(7);

    dq.resize(10);
    cout << "Size: " << dq.size() << "\n";
    
    for (auto it : dq) {
        cout << it << "\n";
    }

    cout << "---------- \n";
    cout << dq[1];
    return 0;
}

