#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();

    if (n % 2 != 0) {
        cout << "Queue size must be even to interleave!" << endl;
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

   
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

   
    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); 
        firstHalf.pop();

        q.push(q.front()); 
        q.pop();
    }
}

void display(queue<int> q) {
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cout << "\nOriginal Queue: ";
    display(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    display(q);

    return 0;
}