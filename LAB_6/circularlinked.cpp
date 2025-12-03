#include <iostream>

using namespace std;

class node{
    public:
        int value;
        node* next;
        
        node(int val){
            value = val;
            next = nullptr;
        }
};

class circularLinkedList{
    private:
        node* head;
    
    public:
        circularLinkedList(){
            head = nullptr;
        }
        
        void insertAtStart(int val){
            node* newNode = new node(val);
            
            if (head == nullptr){
                head = newNode;
                newNode -> next = head;
                return;
            }
            
            node* temp = head;
            while(temp -> next != head){
                temp = temp -> next;
            }
            temp -> next = newNode;
            newNode -> next = head;
            head = newNode;
        }
        
        void insertAtEnd(int val){
            node* newNode = new node(val);
            if (head == nullptr){
                head = newNode;
                newNode -> next = head;
                return;
            }
            
            node* temp = head;
            while(temp -> next != head){
                temp = temp -> next;
            }
            
            temp -> next = newNode;
            newNode -> next = head;
            
        }
        
        void insertAtPos(int pos, int val){
            if (pos == 1){
                insertAtStart(val);
                return;
            }
            
            node* newNode = new node(val);
            node* temp = head;
            
            for(int i =1; i<pos-1; i++){
                temp = temp -> next;
                if (temp == head) {
                    cout << "Position out of range!" << endl;
                    return;
                }
            }
            
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
        
        void deleteAtStart(){
            if (head == nullptr){
                cout<< "empty list";
                return;
            }
            
            if (head -> next == head){
                node* delNode = head;
                head = nullptr;
                delete delNode;
                return;
            }
            
            node* temp = head;
            while(temp -> next != head){
                temp = temp -> next;
            }
            
            node* delNode = head;
            temp -> next = head-> next;
            head = head -> next;
            delete delNode;
            
        }
        
        
        void deleteAtEnd(){
            if (head == nullptr){
                cout<< "empty list";
                return;
            }
            
            if (head -> next == head){
                node* delNode = head;
                head = nullptr;
                delete delNode;
                return;
            }
            
            node* temp = head;
            while(temp -> next -> next != head){
                temp = temp-> next;
            }
            
            node* delNode = temp-> next;
            temp -> next = head;
            delete delNode;
        }
        
        void display() {
            if (head == nullptr) {
                cout << "List is empty!" << endl;
                return;
            }
        
            node* temp = head;
            do {
                cout << temp->value << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
};
    
int main()
{
    return 0;
}