#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    queue<int> radiant;
    queue<int> dire;
    map<int,int>banned;
    for (int i = 0; i < s.length(); i++) {
        banned[i] = -1;
        if (s[i] == 'R'){
            radiant.push(i);
        }
        else {
            dire.push(i);
        }
    }
    int i = 0;
    while (dire.size() >0 && radiant.size() >0){
        if (s[i] == 'R') {
            int dpop = dire.front();
            dire.pop();
            banned[dpop] = 1;
        }
        else if (s[i] == 'D') {
            int rpop = radiant.front();
            radiant.pop();
            banned[rpop] = 1;
        }
        i = (i+1)%s.length();
        if (banned[i] == 1){
            i = (i+1)%s.length();
        }
        cout << dire.size() << " " << radiant.size() << endl;
    }  
    if (dire.size() == 0){
        cout << "Radiant" << endl;
    }
    else {
        cout << "Dire" << endl;
    }
    return;
}

int main() {
    solve("DDRRR");
    return 0;
}