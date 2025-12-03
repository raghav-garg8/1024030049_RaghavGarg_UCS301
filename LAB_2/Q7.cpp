#include <iostream>
#include <vector>
using namespace std;

int count_inversion(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int inversions = count_inversion(arr);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
