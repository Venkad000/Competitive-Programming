#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> nums) {
    stack<int>st;
    st.push(nums[0]);
    int n = nums.size();
    vector<int> result(n);
    for (int i = 0; i < nums.size();i++) {
        if (st.empty()) {
            st.push(nums[i]);
            continue;
        }
        while (st.empty() == false && st.top() < nums[i]){
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(nums[i]);
    }
    while (st.empty() == false) {
        result[st.top()] = -1;
        st.pop();
    }
    for (auto x: result) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    solve(vector<int>{1,2,3,4,3});
}