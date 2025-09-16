#include <iostream>
using namespace std;

#define SIZE 5 

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL!" << endl;
            return;
        }

        if (front == -1) { 
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        cout << value << " added to queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << arr[front] << " removed from queue." << endl;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << " Queue Menu " << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                if (q.isEmpty())
                    cout << "Queue is EMPTY!" << endl;
                else
                    cout << "Queue is NOT EMPTY!" << endl;
                break;

            case 6:
                if (q.isFull())
                    cout << "Queue is FULL!" << endl;
                else
                    cout << "Queue is NOT FULL!" << endl;
                break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}