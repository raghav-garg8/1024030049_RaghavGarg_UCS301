#include<iostream>
using namespace std;
class Stack{
public: 
    int topIndex =-1, st[10];

    int push(int x){
        if(topIndex > 10) return -1;
        topIndex +=1;
        st[topIndex]=x;
        return 0;
    }

    int top(){
        if( topIndex == -1) return -1;
        return st[topIndex];
    }

    void pop(){
        topIndex -= 1;
    }

    int size(){
        if( topIndex == -1) return -1;
        return topIndex+1;
    }
    bool isEmpty(){
        if( topIndex == -1) return true;
        return false;
    }
    bool isFull(){
        if( topIndex == 10) return true;
        return false;
    }
    int display(int x){
        return x;
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(12);
    st.pop();
    cout<<st.display(11)<<endl;
    cout<<st.top()<<endl;
    return 0;
}