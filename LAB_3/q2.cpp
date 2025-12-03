#include <iostream>
#include <stack>
using namespace std;

void pushToStack(stack<string>& st, const string& value) {
    st.push(value);
}

void popAndReverse(stack<string>& st) {
    while (!st.empty()) {
        string word = st.top();
        st.pop();
        for (int i = word.length() - 1; i >= 0; --i) {
            cout << word[i];
        }
    }
}

int main() {
    stack<string> st;
    string text = "DataStructure";

    pushToStack(st, text);
    popAndReverse(st);

    return 0;
}
