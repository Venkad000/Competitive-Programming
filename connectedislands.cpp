#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>isConnected,vector<bool>&visited, int start) {   
    visited[start] = true;
    for (int i = 0; i < isConnected.size(); i++) {
        if (!visited[i] && isConnected[i][start]) {
            dfs(isConnected, visited, i);
        }
    } 
}


int main() {
    vector<vector<int>>isConnected= {
        {1,1,0}, {1,1,0},{0,0,1}
    };
    int result = 0;
    vector<bool>visited(isConnected.size());
    for (int i = 0; i < isConnected.size();i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, i);
            result++;
        }
    }
    cout << result << endl;
    return 0;
}