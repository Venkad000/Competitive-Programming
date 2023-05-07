#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n%2 !=0) {
        cout << -1 << endl;
        return;
    }
    cout << n << " " << n-1 << " ";
    for (int i = 2; i <n ;i+=2) {
        cout << i << " " << n-i-1 << " ";
    }
    cout << endl;
    return;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}