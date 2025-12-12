#include <iostream>
#include <stack>
using namespace std;

string postfix_to_infix(string expression) {
    stack<string>stack;

    for(char c : expression) {
        if(isalnum(c)) {
            stack.push(string(1,c));
        }
        else {

            /*
            for Prefix → Infix conversion: 
            
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            */

            string op2 = stack.top();
            stack.pop();
            string op1 = stack.top();
            stack.pop();

            string curr = "(" + op1 + c + op2 + ")";
            stack.push(curr);
        }
    }

    return stack.top();
}

int main() {
    string s;
    cin >> s;

    cout << postfix_to_infix(s);

    return 0;
}