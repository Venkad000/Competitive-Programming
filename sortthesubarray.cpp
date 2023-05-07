#include <bits/stdc++.h>

using namespace std;;

void solve(vector<int>arr, vector<int>sortedarr) {
    int diffright = -1;
    int diffleft = -1;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] != sortedarr[i]) {
            diffright = i;
            if (diffleft == -1) {
                diffleft = i;
            }
        }
    }

    while (diffright < n-1 && sortedarr[diffright] <= sortedarr[diffright + 1])
        diffright++;
    while (diffleft > 0 && sortedarr[diffleft - 1] <= sortedarr[diffleft])
        diffleft--;
    cout << diffleft + 1 << " " << diffright + 1 << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int>v(n);
        vector<int>vec(n);
        for (int i = 0; i < n ;i++) {
            cin >> v[i];
        }
        for (int i = 0; i < n;i++) {
            cin >> vec[i];
        }
        solve(v, vec);
    }
    // solve(vector<int>{2,2,1}, vector<int>{2,1,2});
}