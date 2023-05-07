#include <bits/stdc++.h>

using namespace std;

int dfs(int i, int j, vector<vector<char>>&vec) {
    int countr = 0;
    int inti = i;
    int intj = j;
    // cout << inti << " " << intj << " " << vec[inti][intj] << endl;
    while (vec[inti][intj] == '#' && inti >=0 && intj >=0) {
        // cout << vec[inti][intj] << " ";
        // cout << inti << " " << intj << " " << vec[inti][intj] << endl;
        inti--; intj--;
        countr++;
    }
    return countr - 1;
}

void solve(int h, int w, vector<vector<char>> &vec) {
    vector<int>result(min(h,w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w;j++) {
            if (i-1 >=0 && i +1 < h && j - 1 >=0  && j + 1 < w) {
                if (vec[i][j] == '#' && vec[i-1][j+1] == '#' && vec[i-1][j-1] == '#' && vec[i+1][j+1] == '#'
                    && vec[i+1][j-1] == '#') {
                        // cout << i << " " << j << endl;
                        int count =  dfs(i,j,vec);
                        result[count-1]++;
                }
            }
        }
    }
    for (auto x: result) {
        cout << x << " ";
    }
    cout << endl;
    return;
}

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>>a(h, vector<char>(w));
    for (int i = 0; i < h;i++){
        for (int j = 0; j < w;j++) {
            cin >> a[i][j];
        }
    }
    solve(h,w,a);
}