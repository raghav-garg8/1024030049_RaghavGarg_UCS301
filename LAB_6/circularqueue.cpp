#include <iostream>

using namespace std;

class circularQueue{
    int *arr;
    int size;
    int front,rear;
    
    public:
        circularQueue(int n){
            size = n;
            arr = new int[size];
            front = rear = -1;
        }
        
        bool isEmpty(){
            return( front == -1);
        }
        
        bool isFull(){
            return ((rear + 1)%size == front);
        }
        
        void enqueue(int x){
            if (isFull()){
                cout<< "queue is full"<< endl;
                return;
            }
            
            if (isEmpty()){
                front = rear = 0;
            }
            else{
                rear = (rear+1)%size;
            }
            
            arr[rear] = x;
        }
        
        
        int peek(){
            if (isEmpty()){
                cout<< "queue is empty";
                return -1;
            }
            
            return arr[front];
        }
        
        void dequeue(){
            if (isEmpty()){
                cout<< "list is empty";
                return;
            }
            if (front == rear){
                front = rear = -1;
            }else{
                front = (front+1)%size;
            }
        }
        
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty!" << endl;
                return;
            }
            cout << "Queue: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
};

class node{
public:
    int val;
    node* next;

    node(int v){
        val = v;
        next = nullptr;
    }
};

class circularQueueLL{
    private:
        node* front;
        node* rear;
        int size;
        int count;
    
    public:
        bool isEmpty() {
            return (count == 0);
        }

        bool isFull() {
            return (count == size);
        }


        circularQueueLL(int s){
            size = s;
            count =0;
            front = nullptr;
            rear = nullptr;
        }

        void enqueue(int x){
            node* newNode = new node(x);
            if (rear == nullptr){
                front = rear = newNode;
                rear -> next = front;
                count++;
                return;
            }
            if (isFull()){
                cout << "full";
                return;
            }

            rear -> next = newNode;
            newNode-> next = front;
            rear = newNode;
            count++;    
        }

        int dequeue(){
            if (isEmpty()){
                cout << "empty";
                return -1;
            }

            node* temp = front;
            front = front -> next;
            rear -> next = front;
            int valu = temp->val;
            delete temp;
            return valu;
        }

};

int main() {
    circularQueue q(5); 

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();  

    q.dequeue();
    q.dequeue();
    q.display();   

    q.enqueue(50);
    q.enqueue(60);
    q.display();   

    q.enqueue(70);
    q.enqueue(80);
    q.display();

    q.dequeue();
    q.enqueue(80);

    q.display();

    cout << "Front element = " << q.peek() << endl; // 40
}

struct queue {
    int* arr;
    int front;
    int rear;
};


int MAX =6;

void enqueue(queue q, int a){
    if (q.front = -1){
        q.front = q.rear = MAX-1;
    }
    if (q.rear == 0)

}