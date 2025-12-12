#include <iostream>
#include <queue>

int main () {

    std :: queue <std :: string> q;

    q.push("Thiru");
    q.push("Alan");
    q.push("Bob");
    q.push("Drake");
    q.push("Robert");

    while (!q.empty()) {
        std :: cout << q.front() << "\n";
        q.pop();
    }
    
    return 0;
}