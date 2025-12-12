#include <iostream>
#include <stack>
using namespace std;

string prefix_to_postfix(string s) {
    stack<string> st;

    // for Prefix Read the postfix expression from left to right.

    for(int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        if(isalnum(c)) {
            st.push(string(1, c));
        } else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string curr = op1 + op2 + c;  // postfix = left right operator
            st.push(curr);
        }
    }

    return st.top();
}

int main() {
    string s = "*+AB-CD";
    cout << "Postfix: " << prefix_to_postfix(s) << endl;
    return 0;
}
