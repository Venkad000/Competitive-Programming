#include <bits/stdc++.h>

using namespace std;

void solve(int n, int k, vector<int>vec) {
    vector<set<int>>sorted;
    vector<set<int>>given;

    for (int i = 0; i < k ; i++) {
        set<int>tempsorted, tempgiven;
        for (int j = i; j < n; j+=k) {
            tempsorted.insert(j+1);
            tempgiven.insert(vec[j]);
        }
        sorted.push_back(tempsorted);
        given.push_back(tempgiven);
    }
    int count = 0;
    for (int i = 0; i < k; i++) {
        for (auto j:sorted[i]) {
            if (given[i].find(j) == given[i].end()) count++;
        }
    }
    if (count == 0) cout << 0 << endl;
    else if(count == 2) cout << 1 << endl;
    else cout << -1 << endl;
    return;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin>>n>>k;
        vector<int>vec;
        int temp = n;
        int inp;
        while(temp--){
            cin >> inp;
            vec.push_back(inp);
        }
        solve(n,k,vec);
    }
    return 0;
}