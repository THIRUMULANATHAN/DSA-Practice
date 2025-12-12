#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePostfix(string s) {
    stack<int> st;
    for(char c : s) {
        if(isdigit(c)) {
            st.push(c-'0');
        } else {
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();

            switch(c) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
                case '^': st.push(pow(op1, op2)); break;
            }
        }
    }
    return st.top();
}

int precedence(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    if(c == '^') return 3;
    return -1;
}

string infixtoPostfix(string s) {
    stack<char> st;
    string result;

    for(char c : s) {
        if(isalnum(c)) {
            result += c;
        } 
        else if(c == '(') {
            st.push(c);
        } 
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        } 
        else { // operator      
            if(c == '^') {  // special case: right-associative
                while(!st.empty() && precedence(c) < precedence(st.top())) {
                    result += st.top();
                    st.pop();
                }
            } else {  // left-associative operators (+, -, *, /)
                while(!st.empty() && precedence(c) <= precedence(st.top())) {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string s = "A + (B * C - D) / E";
    string postfix = infixtoPostfix(s);
    cout << "Postfix: " << postfix << "\n";
    cout << "Value: " << evaluatePostfix(postfix) << "\n";

    return 0;
}
