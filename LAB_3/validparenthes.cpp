#include <iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string a) {
        int n = a.size();
        stack<char> s;

        for (int i = 0; i < n; i++) {
            char ch = a[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            } else {
                if (s.empty())
                    return false;

                if ((ch == ')' && s.top() != '(') ||
                    (ch == '}' && s.top() != '{') ||
                    (ch == ']' && s.top() != '[')) {
                    return false;
                }
                s.pop();
            }
        }

        return s.empty();
    }
};

int main() {
    Solution sol;
    string s = "([{}])";  
    cout << (sol.isValid(s) ? "true" : "false") << endl;
    return 0;
}
