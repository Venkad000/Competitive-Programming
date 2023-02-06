class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1 || s.length() == 0) {
            return s;
        }
        string result = "";
        const int n = s.length();
        bool dp[n+1][n+1];
        for (int i = n-1;i>=0;i--) {
            for (int j = i; j<n;j++) {
                dp[i][j] = s[i] == s[j] && (abs(i-j) < 3 || dp[i+1][j-1]);
                if (dp[i][j] && (result == "" || j - i + 1 > result.length())) {
                    result = s.substr(i,j-i+1);
                }
            }
        }
        return result;
    }
};
