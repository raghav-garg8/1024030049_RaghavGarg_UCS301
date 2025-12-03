#include <vector>
#include<iostream>
#include<stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> & nums){
    int n = nums.size(),i=0;
    stack<int> st;
    vector<int> ng(n,-1);

    for (i=n-1;i>=0;i--){
        while (!st.empty() && st.top()<=nums[1]){
            st.pop();
        }
        if (!st.empty()){
            ng[i] = st.top();
        }

        st.push(nums[i]);

    }

    return ng;
}
