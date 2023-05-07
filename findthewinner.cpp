#include <bits/stdc++.h>

using namespace std;

int findTheWinner(int n, int k) {
    int tempn = n;
    int tempk = k;

    int i = 0;

    vector<int>array(n,1);
    while (tempn > 1) {
        int tempk = k;
        while (tempk > 0) {
            if(tempk == 0) break;
            if (array[i] != -1) {
                tempk--;
            }
            if (tempk == 0) break;
            i = (i+1)%n;
        }
        array[i] = -1;
        tempn--;

        // for (auto x: array) {
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    int resultindex = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == 1) {
            resultindex = i;
            break;
        }
    }
    return resultindex + 1;
}

// void dfs(int currentnode, int target, vector<vector<int>> edges) {
//     if (currentnode == target) {
//         // cout << currentnode << endl;
//         cout << "target found" << endl;
//         return;
//     }
//     // cout << currentnode << endl;
//     for (int i = 0; i < edges.size(); i++) {
//         if (edges[i][0] == currentnode) {
//             dfs(edges[i][1], target, edges);
//         }
//     }
// }

void dfs(int currentnode, int target, vector<vector<int>> redEdges, vector<vector<int>> blueEdges, int evenodd, int& count, bool& foundbool) {
    if (currentnode == target) {
        // cout << currentnode << endl;
        foundbool = true;
        // cout << "target found" << endl;
        return;
    }
    // cout << "current node:" << currentnode << endl;
    if (evenodd % 2 == 0) {
        for (int i = 0; i < redEdges.size(); i++) {
            if (redEdges[i][0] == currentnode) {
                count++;
                // cout << redEdges[i][1] << endl;
                dfs(redEdges[i][1], target, redEdges, blueEdges, evenodd+1, count, foundbool);
            }
        }
    }
    else {
        for (int i = 0; i < blueEdges.size(); i++) {
            if (blueEdges[i][0] == currentnode) {
                count++;
                dfs(blueEdges[i][1], target, redEdges, blueEdges, evenodd+1, count, foundbool);
            }
        }
    }
}

// vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
//     for ()
// }

void dfsvector(int curr, vector<vector<int>>vec, vector<int>&visited, bool& found) {
    if (found){
        return ;
    }
    cout << curr << endl;
    if (find(visited.begin(), visited.end(), curr) != visited.end()) {
        cout << "loop found" << endl;
        found = true;
        // return false;
    }
    
    visited.push_back(curr);
    for (int x = 0; x < vec.size(); x++) {
        if (vec[x][0] == curr) {
            dfsvector(vec[x][1], vec, visited, found);
        }
    }
    visited.clear();
    // return true;
}

// bool slowfast(int slow, int fast, vector<vector<int>>vec) {
//     unordered_map<int, int> umap;
//     for (int i = 0; i < vec.size();i++) {
//         umap[vec[i][0]] = vec[i][1];
//     }
//     int temp = vec.size();
//     while (slow != NULL && fast != NULL) {
//         slow = umap[slow];
//         fast = umap[umap[fast]];
//         cout << slow << " " << fast << endl;
//         if (slow == fast){
//             return false;
//         }
//     }
//     return true;
// }

void findmin(vector<int>vec, int left, int right, vector<int>&result) {
    if (left <= right){
        int mid = (left + right) / 2;
        // cout <<"mid:" << vec[mid] <<" " << mid << endl;
        if ((mid + 1) < vec.size() && (mid - 1) > -1) {
            if (vec[mid] > vec[mid+1] && vec[mid-1] < vec[mid]) {
                // cout << "min: " << vec[mid+1] << endl;
                result.push_back(vec[mid+1]);
                return;
            }   
            else if (vec[mid] < vec[mid+1] && vec[mid] < vec[mid-1]) {
                result.push_back(vec[mid]);
                return;
            }
        }
        else if (mid - 1 <= 0) {
            // cout <<"min:" << vec[0] << endl;
            result.push_back(vec[0]);
            return;
        }
        findmin(vec, left, mid-1, result);
        findmin(vec, mid+1, right, result);
    }
}

// void sortthearray(vector<int>vec) {

// }

// void hitthelottery(int n) {
    
// }

int main() {
    // vector<vector<int>> edges = {
    //     {0,1}, {0,2}
    // };
    // vector<vector<int>> blueEdges = {
    //     {1,0}
    // };
    
    // for (int i = 0; i < 3 ; i++) {
    //     int rbcount = 0;
    //     int brcount = 0;
    //     bool rbbool = false;
    //     dfs(0, i, edges, blueEdges, 0, rbcount, rbbool);
    //     bool brbool = false;
    //     dfs(0, i, edges, blueEdges, 1, brcount, brbool);

    //     if (rbbool && brbool) {
    //         cout << i << ":" << rbcount << " " << brcount << endl;
    //     }
    //     else if (rbbool && !brbool) {
    //         cout << i << ":" << rbcount << endl;
    //     }
    //     else if (!rbbool && brbool) {
    //         cout << i << ":" << brcount << endl;
    //     }
    //     else {
    //         cout << -1 << endl;
    //     }
    // }
    // // int brcount = 0;
    // // bool foundbool = false;
    // // dfs(0,2,edges, blueEdges, 0, brcount, foundbool);
    // // cout << foundbool << endl;

    // vector<vector<int>> edges = {
    //     {0,1},{2,1},{2,0}
    // };
    // bool result = true;
    // for (int i = 0; i <3;i++) {
    //     // vector<int> visited = {};
    //     // result&=dfsvector(i,edges, visited, false);
    //     cout << slowfast(i,i,edges) << endl;
    // }
    // slowfast(0,0,edges);
    // vector<int> visited = {};
    // bool found = false;
    // dfsvector(1,edges, visited,found);
    // cout << found << endl;

    // cout << result << endl;
    vector<int> vec = {4,5,1,2,3};
    vector<int>result;
    findmin(vec, 0, vec.size()-1, result);
    cout << "min:" << *min_element(result.begin(), result.end()) << endl;

    return 0;
}