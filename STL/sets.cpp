/*
Supports iterator
not supports index
Set:
    i) set               -> unique elements, sorted [ascending]
    ii) multiset         -> not unique, sorted
    iii) unordered_set   -> unique, not sorted
            |_> works basis of Hash tables 
            -> insertion: O(1)
            -> very minor worst [minute case] RARE goes upto O(n) for some function
*/

/*
Set - erase 
    * can be done by the s.erase(elemnet)
    * also s.erase(iterator)
    
    *std::set<int> s = {10, 20, 30, 40};

    std::set<int>::iterator it = s.find(30);
    if (it != s.end()) {
        s.erase(it);  // erase by iterator
    }
*/

#include <iostream>
#include <set>

int main () {
    // safe useage to dereference the "end_iterator" else garabge value might return
    std :: set <int> s = {90, 10, 70};
    // s.insert(90);
    // s.insert(10);
    // s.insert(70);
    // s.insert(20);


    std :: set<int> :: iterator it1 = s.find(90);
    std :: set<int> :: iterator it2 = s.find(0);
    std :: set<int> :: iterator it3 = s.end();

    // the end() & find(not present value) => the same result
    // usually it points to the last before to avoid unwanted dereferencing
    std :: cout << "it1: " << *it1 << "\n";
    std :: cout << "it2: " << *it2 << "\n";
    std :: cout << "it3: " << *it3 << "\n";

    for (std :: set<int> :: iterator it = s.begin(); it != s.end(); ++it) {
        std :: cout << *(it) << "\n";
    }

    // for descding order set

    std :: set<int, std :: greater<int>> s_desc;

    return 0;
}