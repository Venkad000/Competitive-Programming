#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    vector<vector<int>>vec(2, vector<int>(n,0));
    int i = 1;
    int up = 1;

    for (i = 0; i < n;i++) {
        if (up == 1) vec[1][i] = (i+1);
        else vec[0][i] = (i+1);
        up = (up + 1)%2;
    }

    for (int j = 1; j < n;j++) {
        if (up == 1) vec[1][j] = (i+1);
        else vec[0][j] = (i+1);
        up = (up + 1)%2;
        i++;
    }vec[0][0] = 2 * n;
    for (int j = 0; j < vec.size(); j++) {
        for (int k = 0; k < vec[j].size(); k++) {
            cout << vec[j][k] << " ";
        }
        cout << endl;
    }
    
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        solve(n);
    }
    // solve(6);
}