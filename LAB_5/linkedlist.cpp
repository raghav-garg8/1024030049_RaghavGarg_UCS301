#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node (int val){
            data = val;
            next = nullptr;
        }
};

class singlylinkedlist{
    private:
        Node* head;
        
    public:
        singlylinkedlist(){
            head = nullptr;
        }
        
        void insertAtBeggining(int val){
            Node* newNode = new Node(val);
            newNode -> next = head;
            head = newNode;
        }
        
        void insertAtEnd(int val){
            Node* newNode = new Node(val);
            
            if (head == nullptr){
                head = newNode;
                return;
            }
            
            Node* temp = head;
            while(temp -> next != nullptr){
                temp = temp -> next;
            }
            
            temp -> next = newNode;
            
        }
        
        void deleteByValue(int val){
            if (head == nullptr){
                return;
            }
            
            if(head->data == val){
                Node* toDelete = head;
                head = head -> next;
                delete toDelete;
                return;
            }
            
            Node* temp = head;
            while(temp -> next != nullptr && temp -> next -> data == val){
                temp = temp -> next;
            }
            
            Node* toDelete = temp;
            temp -> next = temp -> next -> next;
            delete toDelete;
            
        }
        
        void display(){
            Node* temp = head;
            while (temp != nullptr){
                cout<< temp -> data << " ";
                temp = temp -> next;
            }
            cout << "NULL" << endl;
        }
};


int main()
{
    
    singlylinkedlist lis;
    
    for(int i =0; i< 5; i++){
        lis.insertAtBeggining(i);
    }
    
    lis.deleteByValue(4);
    lis.display();
    
    
    return 0;
}