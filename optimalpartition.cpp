#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    int numberOfParitions = 0;
    unordered_map<char, int> umap;
    for (int i = 0; i < s.length();i++) {
        if (umap.find(s[i]) == umap.end()) {
            umap[s[i]] = 1;
        }
        else {
            cout << "clearing" << endl;
            numberOfParitions++;
            umap.clear();
            umap[s[i]] = 1;
        }
        for (auto x: umap) {
            cout << x.first << " " << x.second << endl;
        }
    }
    cout << numberOfParitions << endl;
}

int main() {
    solve("ssssss");
}