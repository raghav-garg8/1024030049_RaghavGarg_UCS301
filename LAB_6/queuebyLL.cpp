#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        
        Node(int val){
            value = val;
            next = nullptr;
        }
};

class Queue{
    private:
        Node* front;
        Node* rear;
        
    public:
        
        Queue(){
            front = rear = nullptr;
        }
    
        bool isEmpty(){
            return (front == nullptr);
        }
        
        void enqueue(int x){
            Node* newNode = new Node(x);
            if (rear == nullptr){
                front = rear = newNode;
                return;
            }
            
            rear -> next = newNode;
            rear = newNode;
        }
        
        void dequeue(){
            if (front == nullptr){
                cout<< "Empty Queue";
                return;
            }
            
            Node* temp = front;
            front = front -> next;
            if (front == nullptr){
                rear = nullptr;
            }
            
            delete temp;
        }
        
        int peek(){
            if (front == nullptr){
                cout<< "Empty Queue";
                return -1;
            }
            
            return front -> value;
        }
        
        void display(){
            if (front == nullptr){
                cout<< "Empty Queue";
                return;
            }
            
            Node* temp = front;
            while(temp -> next != nullptr){
                cout<< temp-> value<<" ";
                
                temp = temp -> next;
            }
            cout << " End";
        }
        
        
};

int main()
{

    return 0;
}