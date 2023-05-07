#include <bits/stdc++.h>

using namespace std;

int func(int n , int m) {
    int count = 0;
    while (m != n) {
        if (m > n) {
            if (m%2 == 0) {
                m = m / 2;
            }
            else {
                m = m + 1;
            }
            
        }
        else if (n > m) {
            m++;
        }
        // cout << n << " " << m << endl;
        count++;
    }
    return count;
}
int main() {
    int n;
    int m;
    cin >> n >> m;
    int count = 0;
    if (n == m) {
        cout << 0 << endl;
        return 0;
    }
    else if (n > m) {
        cout << n - m << endl;
        return 0;
    }
    cout << func(n,m) << endl;
    return 0;
}