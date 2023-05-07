#include <bits/stdc++.h>

using namespace std;

bool differByOne(string s, string a) {
    int diff = 0;
    for (int i = 0; i < s.size();i++) {
        if (s[i] != a[i]) {
            diff++;
        }
    }
    return diff == 1;
}
vector<int>minvector;
vector<string>visited;
void dfs(string s, string target, vector<string> bank, int count) {
    if (s == target) {
        cout << "target reached" << endl;
        minvector.push_back(count);
        return;
    }
    visited.push_back(s);
    cout << "current string:" << s << endl;
    for (int i = 0; i < bank.size(); i++) {
        if (differByOne(s, bank[i])) {
            if (find(visited.begin(), visited.end(), bank[i]) == visited.end())
                dfs(bank[i], target, bank, count + 1);
        }
    }
}

int main() {
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    dfs("AACCGGTT", "AAACGGTA", bank, 0);
    // cout << "min distance:" << endl;
    // for (auto x: minvector) {
    //     cout << x << " ";
    // }
    // cout << endl
}