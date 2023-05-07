#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, pair<int,int>>umap;
    for (auto x: nums1){
        umap[x] = pair<int,int>(1,0);
    }
    for (auto x: nums2) {
        if (umap.find(x) == umap.end()) umap[x] = pair<int,int>(0,1);
        else{
            pair<int,int> temp = umap[x];
            temp.second = 1;
            umap[x] = temp;
        }
    }
    vector<int>result1;
    vector<int>result2;

    for (auto x: umap) {
        if (x.second == pair<int,int>(1,0)){
            result1.push_back(x.first);
        }
        else if (x.second == pair<int,int>(0,1)){
            result2.push_back(x.first);
        }
    }
    for (auto x: result1) {
        cout << x << " ";
    } 
    cout << endl;

    for (auto x: result2) {
        cout << x << " ";
    }
    cout << endl;

    vector<vector<int>>result;
    result.push_back(result1);
    result.push_back(result2);
    return result;

}

int main() {
    vector<int>v1 = {1,2,3,3};
    vector<int>v2 = {1,1,2,2};
    findDifference(v1, v2);
}