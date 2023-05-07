#include <bits/stdc++.h>

using namespace std;

void solve(vector<long long>vec) {
    if (vec.size() == 2) {
        cout << vec[0] * vec[1] << endl;
        return;
    }
    sort(vec.begin(), vec.end());
    cout << max(vec[0] * vec[1], vec[vec.size()-1] * vec[vec.size()-2]) << endl;
    return;
}

int main() {    
    long long tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long>vec(n);
        for (int i = 0; i < n;i++) {
            cin >> vec[i];
        }
        solve(vec);
    }
    return 0;
}