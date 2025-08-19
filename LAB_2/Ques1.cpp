#include <iostream>
using namespace std;

// Linear Search: O(n)
int linearSearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value)
            return i; 
    }
    return -1; 
}


int binarySearch(int arr[], int n, int value) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // prevents overflow
        if (arr[mid] == value)
            return mid; // found
        else if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // not found
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value= 14;

    // Linear Search
    int index1 = linearSearch(arr, n, value);
    cout << "Linear Search index: " << index1 << endl;

    // Binary Search
    int index2 = binarySearch(arr, n, value);
    cout << "Binary Search index: " << index2 << endl;

    return 0;
}
