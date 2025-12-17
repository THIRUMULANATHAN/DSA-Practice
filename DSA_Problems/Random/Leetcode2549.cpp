#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// BRUTE 

// int distinctIntegers(int n) {
//     unordered_set<int> seen;
//     vector<int> arr;
//     for(int i=1; i<=n; i++) {
//         if(n%i==1) {
//             seen.insert(i);
//             arr.push_back(i);
//         }
//     }

//     for (size_t i = 0; i < arr.size(); i++) {
//         for (int index = 1; index <= arr[i]; index++) {
//             if (arr[i] % index == 1) {
//                 seen.insert(index);
//                 arr.push_back(index);
//             }
//         }
//     }

//     seen.insert(n);
//     return size(seen);
// }

// BETTER

int distinctIntegers(int n) {
    return (n==1) ? 1 : n-1;
}

int main() {
    int n; cin >> n;
    cout << distinctIntegers(n);
    return 0;
}