#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        // Check if arr[i] has appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) {
            count++;
        }
    }

    return count;
}

int main() {
    int arr[] = {4, 5, 2, 4, 2, 8, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Number of distinct elements: " << countDistinct(arr, n) << endl;
    return 0;
}
