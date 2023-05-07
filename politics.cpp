#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        int k;
        cin>>n>>k;
        string s[n];
        int ans = n;
        for (int i =0;i < n;i++) {
            cin >> s[i];
            if (s[i] != s[0])
                ans--;
        }
        cout << ans << endl;
    }
    return 0;
}