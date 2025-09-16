#include<iostream>
using namespace std;
class Queue{
public: 
    int st[10], start=-1, end = -1, size=0, itlSize=10;
    int push(int x){
        if(size==itlSize) return -1;
        if(size== 0){
            start =0; end =0;
        }else{
            end = (end+1)%itlSize;
            size++;
            st[end]=x;
        }
    }
    int top(){
        if (size ==0 ) cout<<"Queue Empty"<<endl;
       return st[start];
    }
    void pop(){
       if (size ==0 ) cout<<"Queue Empty"<<endl;
       if(size == 1) start = end = -1;
       else{
         start = (start+1)%itlSize;
         size--;
       }
    }
    int size(){
        if (size ==0 ) cout<<"Queue Empty"<<endl;
        return size;
    }
    bool isEmpty() {
        return (start == 0);
    }

    bool isFull() {
        return (end == 10 - 1);
    }
};

int main(){
    Queue st;
    st.push(10);
    st.push(12);
    st.pop();
    cout<<st.top()<<endl;
    return 0;
}