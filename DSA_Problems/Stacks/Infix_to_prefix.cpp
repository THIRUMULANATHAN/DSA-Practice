#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3; // exponent has highest precedence
    return -1;
}

string infix_to_postfix(string exp) {
    stack<char> st;
    string result;

    for (char c : exp) {
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            st.push(c);
        }
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else { // operator
            while (!st.empty() && precedence(c) <= precedence(st.top())) {
                if (c == '^' && st.top() == '^') break; // right associativity
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

string infix_to_prefix(string infix) {
    // Step 1: reverse
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Step 2: infix (reversed) → postfix
    string postfix = infix_to_postfix(infix);

    // Step 3: reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string s = "(A+B)*(C-D)";
    cout << "Infix: " << s << endl;
    cout << "Prefix: " << infix_to_prefix(s) << endl;
    return 0;
}
