#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>result;

void dfs(int currentNode, int target, vector<int>visited, vector<vector<int>>graph) {
    if (currentNode == target) {
        visited.push_back(currentNode);
        result.push_back(visited);
        // visited.clear();
        return;
    }
    // cout << currentNode << endl;
    visited.push_back(currentNode);
    for (int i = 0; i < graph[currentNode].size(); i++) {
        dfs(graph[currentNode][i], target, visited, graph);
    }
}

int main() {
    vector<int>visited;
    vector<vector<int>>graph = {
        {4,3,1},{3,2,4},{3},{4},{}
    };
    dfs(0, 4, visited, graph);
    for (int i = 0; i < result.size();i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " " ;
        }
        cout << endl;
    }
    return 0;
}