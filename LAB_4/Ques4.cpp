#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cout << "Enter string (with spaces if needed): ";
    getline(cin, s);

    queue<char> q;
    int freq[26] = {0}; 

    cout << "Output: ";
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch == ' ') continue; 

        freq[ch - 'a']++;   
        q.push(ch);        

        
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

       
        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }

    cout << endl;
    return 0;
}