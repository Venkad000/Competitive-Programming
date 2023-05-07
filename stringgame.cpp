#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
    int count = 0;
    bool ramos = true;
    bool zlatan = true;
    size_t sit01;
    size_t sit10;
    string s01 = "01";
    string s10 = "10";
    while (sit01 != string::npos && sit10 != string::npos) {
        
        sit01 = s.find(s01);
        // if (sit01 != string::npos) s.erase(sit01, 2);
        // else if(sit01 == string::npos) break;
        sit10 = s.find(s10);
        // if (sit10 != string::npos) s.erase(sit10,2);
        // else if (sit10 == string::npos) break;
        if (sit10 != string::npos && sit01 !=string::npos) continue;
        else if (sit10 == string::npos && sit01 !=string::npos) s.erase(sit01,2);
        else if (sit10 != string::npos && sit01 ==string::npos) s.erase(sit10,2);
        else break;
        count++;
    }
    cout << count << endl;
    return;
}

int main() {
    solve("101");
    return 0;
}