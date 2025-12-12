#include <iostream>
#include <vector>

#define v vector<int> 
#define v_pair vector<pair<string, string>>

using namespace std;


int main() {
    v nums;

    int n = 5;
    for (int i = 0; i < n; i++)
    {
        int n; cin >> n;
        nums.push_back(n);
    }

    
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    string name; 
    string dept;

    v_pair vp;

    for (int i=0; i<5; i++) {
        cin >> name;
        cin >> dept;
        vp.push_back(make_pair(name, dept));
    }
    
    for (pair<string, string>&pr : vp) {
        cout << pr.first << " " << pr.second << " ";
    }
    return 0;
} 