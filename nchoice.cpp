#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> vec, int n, int a, int b) {
    int sum = a+ b;
    for (int i = 0; i < n; i++) {
        if (vec[i] == sum) return i + 1;
    }
    return -1;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> vec(n);
    for (int i = 0; i < n;i++) {
        cin >> vec[i];
    }
    cout << solve(vec, n, a, b) << endl;
}