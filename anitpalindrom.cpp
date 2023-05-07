#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
    if (s.length() % 2 == 1) {
        return -1;
    }
    int distinctpairs = 0;
    int samepairs = 0;
    int n = s.length();
    for (int i = 0; i < n/2;i++) {
        if (s[i] == s[n-i-1]) samepairs++;
        else distinctpairs++;
    }
    if (samepairs%2  == 1){
        return -1;
    }
    return samepairs/2;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        cout << solve(s) << endl;
    } 
    return 0;
}