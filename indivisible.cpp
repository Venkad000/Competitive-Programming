#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if ((n*(n+1)/2) % n == 0) {
        cout << " -1 " << endl;
        return;
    }
    for (int i = 0; i < n - 1 ; i+=2) {
        cout << i + 2 << " " << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        solve(n);
    }
}