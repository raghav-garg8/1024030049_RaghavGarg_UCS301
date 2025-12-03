#include <vector>
#include <iostream>
using namespace std;

//duplicate zero

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        if (arr.empty()) return;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 2) {
                for (int j = arr.size() - 1; j > i; j--) {
                    arr[j] = arr[j - 1];
                }
                i++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,0,2,3,0,4,5,0};

    sol.duplicateZeros(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}
