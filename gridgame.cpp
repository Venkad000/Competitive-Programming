#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    int vcurrent = 0;
    int hcurrent = 0;
    for (int i = 0; i < s.length();i++) {
        if (s[i] == '0') {
            cout << 2 << " " << vcurrent + 1 << endl;
            vcurrent = (vcurrent + 1) % 4;
        }
        else {
            cout << 1 << " " << hcurrent + 1 << endl;
            hcurrent = (hcurrent + 2) % 4;
        }
    }
    return;
}

int main() {
    string s;
    cin >> s;
    solve(s);
}