#include<iostream>
using namespace std;

class solution{
public:
    string reverseStr(string s){
        string rev;
        stack<char> st;
        for(char c:s){
            st.push(c);
        }while(!st.empty()){
            rev+=st.top();
            st.pop();
        }
        return rev;
    }
};

int main(){
    solution sol;
    string s="DataStructures";
    cout<<sol.reverseStr(s)<<endl;
    return 0;
}