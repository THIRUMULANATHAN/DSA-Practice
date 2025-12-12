#include <iostream>
#include <queue>
#include <vector>

int main () {

    // max heap
    std :: priority_queue <int> pq;

    pq.push(10);
    pq.push(9);
    pq.push(8);
    pq.push(7);
    pq.push(99);

    while (!pq.empty()) {
        std :: cout << pq.top() << "\n";
        pq.pop();
    }

    std :: priority_queue <std :: string> spq;

    spq.push("Thiru");
    spq.push("Alan");
    spq.push("Alice");
    spq.push("Bob");
    spq.push("Drake");
    spq.push("Robert");

    while (!spq.empty()) {
        std :: cout << spq.top() << "\n";
        spq.pop();
    }

    // ------------------------------------------

    // min heap

    std :: priority_queue <int, std :: vector <int>, std :: greater <int>> min_pq;
    return 0;
}


/*
priority_queue:
    > it used commonly in graphs and trees 
    > used to find the shortest path 
    > K greater element (LeetCode)

    Heap:
     i) max Heap
     ii) min Heap

   // priority_queue uses => max heap by default
   // swapping done only betweem the container
        eg: [--  pq1.swap(pq2)  --]
*/