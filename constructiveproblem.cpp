#include <bits/stdc++.h>

using namespace std;

int mex(vector<int>vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()) , vec.end());
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        if (vec[i] != i) {
            return i;
        }
    }
    return n; 
}

bool solve(vector<int> vec) {
    int n = vec.size();
    if (vec.size() == 1) {
        if (vec[0] == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    int prevmex = mex(vec);
    // cout << "prev mex:" << prevmex << endl;
    int requiredmex = prevmex + 1;
    map<int, int> leftOcc, rightOcc;
    for (int i = 0; i < vec.size();i++) {
        rightOcc[vec[i]] = i;
        if (leftOcc.count(vec[i]) == 0) {
            leftOcc[vec[i]] = i;
        }
    }

    if (leftOcc.count(requiredmex) > 0) {
        int L = leftOcc[requiredmex];
        int R = rightOcc[requiredmex];

        for (int i = L; i <= R; i++) {
            vec[i] = prevmex;
        }
        int newmex = mex(vec);
        assert(newmex <= requiredmex);
        return newmex == requiredmex;
    }

    for (int i = 0; i < n; i++) {
        if (vec[i] > prevmex || leftOcc[vec[i]] != rightOcc[vec[i]])  {
            return true;
        }
    }
    return false;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int>vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        if (solve(vec)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    // solve(vector<int>{1,2,1});
    return 0;
}