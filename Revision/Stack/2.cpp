#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    stack<int> stack;
    vector<bool> inStack(26, false);

    for(char c : s) {
        freq[c-'a']++;
    }

    for(char c : s) {
        freq[c-'a']--;
        if(inStack[c-'a'])continue;

        while(!stack.empty() && stack.top() > c && freq[stack.top()-'a'] > 0) {
            inStack[stack.top()-'a'] = false;
            stack.pop();
        }

        inStack[c-'a'] = true;
        stack.push(c);
    }

    string result;
    while(!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    
    reverse(result.begin(), result.end());
    cout << result;

    return 0;
}