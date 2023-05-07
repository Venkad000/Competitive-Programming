#include <bits/stdc++.h>

using namespace std;

long long mod = 10e9 + 7;

int solve(vector<int> vec, int target) {
    int r = vec.size() - 1;
    int res = 0;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size();i++) {
        while (vec[i] + vec[r] > target && i <= r) {
            r--;
        }
        if (i <= r) {
            res += pow(2, (r-i));
            res %= mod;
        }
    }
    return res;
}

int main() {
    cout << solve(vector<int>{2,3,3,4,6,7}, 12) << endl;
}