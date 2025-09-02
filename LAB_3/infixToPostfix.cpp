#include<iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='-'|| c=='+') return 1;
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string ans;
    

    for(char ch:s){
        if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z' || ch>='0'&&ch<='9'){
            ans+=ch;
        }

        else if(ch=='('){
            st.push(ch);
        }

        else if(ch==')'){
            while(st.top()!='(' && !st.empty()){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }   
        else {
            
            while (!st.empty()&& priority(st.top())>= priority(ch)){
                ans+=st.top();
                st.pop();
            }
            st.push(ch);
        }
       
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    string s="a+b*(c^d-e)";
   
    cout<<infixToPostfix(s);
    return 0;
}