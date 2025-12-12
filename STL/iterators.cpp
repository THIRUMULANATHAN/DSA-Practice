#include <iostream>
#include <vector>

#define v_pair vector<pair<string, string>>

using namespace std;

void print_vector(v_pair vp) {
    for (v_pair :: iterator it = vp.begin(); it != vp.end(); ++it) {
        cout << (*it).first << " - " << (*it).second << "\n";
    }
}

int main () {
    v_pair vp = {{"Thiru", "EEE"}, {"Alice", "ECE"}, {"Bob", "ME"}, {"Chris", "CS"}};

    // 1 Insert
    vp.insert(vp.begin(), make_pair("Hari", "Civil"));
    vp.insert(vp.begin() + 3, 4, make_pair("Spongebob", "AIDS")); // insert at [position] , no of times , element to insert
    print_vector(vp);

    cout << "-------------------------------------- \n";
    // 2 Erase
    vp.erase(vp.begin()); // erase at
    vp.erase(vp.begin()+2, vp.begin() + 6);
    print_vector(vp);

    // 3 swap
    // vec2.swap(vec1);

    return 0;
}



//--------------------------------Iterators---------------------------------

// for (v_pair :: iterator it = vp.begin(); it != vp.end(); ++it) {
//     cout << (*it).first << " - " << (*it).second << "\n";
// }

// generally preffered over the data types where the index bassed accesing is not preferred
// gives more control over the for each loop
// safe access 


/*
Container	        Why not []?
set	Ordered,        but no position/index concept
unordered_set	    No order at all
map	                Use keys (m[key]), not index
unordered_map	    Same as map
list	            Doubly linked list — no random access
forward_list	    Singly linked list
*/


/*
10        s.begin()
20
30
40
50        last elemnt
nothing   s.end()   Cannot derefernce
*/