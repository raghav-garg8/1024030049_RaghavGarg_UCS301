#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
    public: 
        typedef struct {
            int data[MAX];
            int topIndex;
        } StackData;

        StackData init() {
            StackData s;
            s.topIndex = -1;
            return s;
        }

        int isEmpty(StackData s) {
            return s.topIndex == -1;
        }

        int isFull(StackData s) {
            return s.topIndex == MAX - 1;
        }

        int peek(StackData s) {
            if (!isEmpty(s)) {
                return s.data[s.topIndex];
            }
            return -1;
        }

        StackData push(StackData s, int value) {
            if (isFull(s)) {
                cout << "Overflow" << endl;
                return s;
            }
            ++s.topIndex;
            s.data[s.topIndex] = value;
            return s;
        }

        StackData pop(StackData s) {
            if (isEmpty(s)) {
                cout << "Underflow" << endl;
                return s;
            }
            --s.topIndex;
            return s;
        }

        void display(StackData s) {
            for (int i = s.topIndex; i >= 0; --i) {
                cout << s.data[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Stack stackObj;
    Stack::StackData s = stackObj.init();

    s = stackObj.push(s, 10);
    s = stackObj.push(s, 20);
    s = stackObj.push(s, 30);

    stackObj.display(s);

    s = stackObj.pop(s);
    stackObj.display(s);

    return 0;
}
