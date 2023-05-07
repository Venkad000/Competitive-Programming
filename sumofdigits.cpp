#include <bits/stdc++.h>

using namespace std;

vector<int>maxvec;

void func(int length, int number) {
    if (length <= 0)
        return;
    if (number == 0) {
        while(--length) {
            maxvec.push_back(0);
        }
    }
    if (length == 1 ) {
        maxvec.push_back(number);
        return;
    }
    int max_number = -1;
    if ( number < 10)
        max_number = min(number, 9);
    else
        max_number = 9;
    maxvec.push_back(max_number);
    func(length-1, number - max_number);
}

int main() {
    int len;
    int sum;
    cin >> len >> sum;
    if (len == 1 && sum == 0) {
        cout << 0 << " "<< 0 << endl;
        return 0;
    }
    if ((sum == 0 && len > 1) || sum > len * 9) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    func(len, sum);

    
    vector<int>minvec;
    vector<int>tempvec;
    minvec = maxvec;
    tempvec = maxvec;
    if (find(maxvec.begin(), maxvec.end(), 0) == maxvec.end()) { //0 not in the max
        reverse(minvec.begin(), minvec.end());
        for (auto x: minvec) {
            cout << x;
        }
    }
    else {
        for (int i = tempvec.size() - 1; i >= 0 ; i--) {
            if (tempvec[i] != 0) {
                tempvec[i]--;
                tempvec[tempvec.size()-1] = 1;
                reverse(tempvec.begin(), tempvec.end());
                break;
            }
        }
        for (auto x: tempvec) {
            cout << x;
        }
    }
    cout << " " ;
    for (auto x: maxvec) {
        cout << x;
    }
    cout << endl;
    return 0;
}