#include <bits/stdc++.h>

using namespace std;

bool isVowel(char s) {
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
        return true;
    }
    return false;
}

int solve(string s, int k) {
    int startLPos = -1;
    int startRightPos = -1;
    for (int i = 0; i < s.length();i++) {
        if (isVowel(s[i])) {
            startRightPos = i;
            if (startLPos == -1) {
                startLPos = i;
            }
        }
    }
    if (startLPos == -1 && startRightPos == -1) {
        return 0;
    }
    int vowelsInWindow = 0;
    int maxVowels = -1;
    for (int i = startLPos; i < startLPos + k; i++) {
        if (isVowel(s[i])) {
            vowelsInWindow++;
        }
    }
    maxVowels = max(vowelsInWindow, maxVowels);
    for (int i = startLPos; i <= startRightPos - k;i++) {
        if (isVowel(s[i])) vowelsInWindow--;
        if (isVowel(s[i + k])) vowelsInWindow++;
        cout << "Vowels in window:" << vowelsInWindow << endl;
        maxVowels = max(maxVowels, vowelsInWindow);
    }
    cout << "maxVowels:"  << maxVowels << endl;
}

int main() {
    solve("rhythms" ,4);
}