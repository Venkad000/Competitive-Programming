#include <bits/stdc++.h>

using namespace std;

int solve(string s, char save) {
    int current = 0;
    int maxsize = 0;

    for (int i = 0; i < s.length();i++) {
        if (s[i] == save) {
            maxsize = max(maxsize , current);
            current = 0;
            continue;
        }
        current++;
    }

    maxsize = max(maxsize, current);

    int count = 0;
    while (maxsize) {
        maxsize>>=1;
        count++;
    }
    return count;
}

int main() {    
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        int minanswer = INT_MAX;
        for (int i = 0; i < 26;i++) {
            char save = 'a' + i;
            minanswer = min(minanswer, solve(s, save));
        }
        cout << minanswer << endl;
    }
    return 0;
}