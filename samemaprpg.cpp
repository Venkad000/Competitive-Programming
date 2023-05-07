#include <bits/stdc++.h>

using namespace std;
 
void solve(vector<vector<char>> a, vector<vector<char>>b, int h, int w) {
    for (int s = 0; s < h;s++) {
        for (int t = 0; t < w; t++) {
            bool result = true;
            for (int i = 0; i < h;i++) {
                for (int j = 0; j < w;j++) {
                    if (a[(i - s + h) % h][(j - t + w) % w] != b[i][j]) result = false;
                }
            }
            if (result) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}


int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>>a(h, vector<char>(w));
    vector<vector<char>>b(h, vector<char>(w));
    for (int i = 0; i < h;i++){
        for (int j = 0; j < w;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h;i++){
        for (int j = 0; j < w;j++) {
            cin >> b[i][j];
        }
    }
    solve(a, b, h, w);
}