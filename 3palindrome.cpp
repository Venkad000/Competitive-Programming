#include <bits/stdc++.h>

using namespace std;

string solve(int n) {
    if (n == 1) {
        return "a";
    }
    if (n == 2) {
        return "ab";
    }
    if (n == 3) {
        return "abb";
    }
    string result =  "abb";
    int ind = 1;
    int temp = n - 3;
    while (temp--) {
        if (result[ind] == 'a') {
            result+='b';
        }
        else {
            result+='a';
        }
        ind++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    // cout <<  solve(5) << endl;
    return 0;
}