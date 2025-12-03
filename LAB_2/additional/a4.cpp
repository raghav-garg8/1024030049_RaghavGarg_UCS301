#include <iostream>
using namespace std;
// DUTCH FLAG

void sort_better(int arr[], int size) {
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low++], arr[mid++]);
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high--]);
        }
    }
}

int main() {
    int arr[] = {0, 1, 2, 0, 1, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort_better(arr, size);

    return 0;
}