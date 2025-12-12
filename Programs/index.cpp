#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int freq[26] = {0};
    bool inStack[26] = {false};

    for (char c : s) {
        freq[c-'a']++;
    }

    stack<char> st;
    for (char c : s) {
        freq[c-'a']--;

        if(inStack[c-'a']) continue;

        while(!st.empty() && st.top() > c && freq[st.top() - 'a'] != 0) {
            inStack[c-'a'] = false;
            st.pop();
        }
        inStack[c-'a'] = true;
        
        st.push(c);
    }

    string result = "";
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}