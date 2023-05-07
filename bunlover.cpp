#include <bits/stdc++.h>

using namespace std;

void solve(long long n) {
    cout << n * 4 + 1 + (n-2)*(n-1)/2 + (n)*(n-1)/2 << endl;
}

int main() {    
    long long tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        solve(n);
    }
    return 0;
}