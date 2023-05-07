#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, int s) {
    if ((n-1) * k < s) {
        cout << "NO" << endl;
        return;
    }

    int moveslen = s/(n-1) + 1;
    int i = 0;
    cout << 1 << " ";
    for (i = 0; i < (k-1);i++) {
        if (i%2 == 0) cout << moveslen + 1 << " ";
        else cout << 1 << " ";
    }    

    if (i%2 == 0) {
        cout << s % moveslen + 1 << endl;
        return;
    }
    cout << moveslen - (s % moveslen) + 1 << endl;
    return;
}

int main() {
    solve(10,2,15);
}