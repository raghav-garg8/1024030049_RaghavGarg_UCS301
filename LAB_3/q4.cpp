#include <bits/stdc++.h>
using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string result;

    for (char c : infix) {
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
            st.pop(); // remove '('
        } 
        else { // operator
            while (!st.empty() && precedence(st.top()) >= precedence(c)) {
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

int main() {
    string infix = "(A-B/C)*(A/K-L)";
    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
