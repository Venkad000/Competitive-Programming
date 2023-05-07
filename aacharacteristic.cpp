#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k) {
    for (int i = 0; i < n; i++) {
        int pos = i;
        int neg = n - i;    
        if (pos*(pos-1) + neg*(neg-1) == 2*k) {
            cout << "YES" << endl;
            for (int j = 0; j < pos;j++) {
                cout << 1 << " ";
            }
            for (int j = 0; j < neg; j++) {
                cout << -1 << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main() {
    // int tt;
    // cin >> tt;
    // while (tt--) {
    //     int n,k;
    //     cin >> n >> k;
    //     solve(n,k);
    // }
    cout << (1-3)%4 << endl;
    return 0;
}