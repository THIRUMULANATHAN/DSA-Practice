#include <iostream>
#include <stack>
using namespace std;

string prefix_to_postfix(string s) {
    stack<string> stack;

    for(int i=s.length()-1; i>=0; i--) {
        char c = s[i];
        if(isalnum(c)) {
            stack.push(string(1,c));
        }
        else {
            string op1 = stack.top(); stack.pop();
            string op2 = stack.top(); stack.pop();
            string curr = op1 + op2 + c;
            stack.push(curr);
        }
    }

    return stack.top();
}

int main() {
    string s;
    cin >> s;

    cout << prefix_to_postfix(s);
    return 0;
}