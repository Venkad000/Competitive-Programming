class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>se;
        int begin = 0;
        int end = 0;
        int maxi = 0;
        
        while (begin < s.size()) {
            auto it = se.find(s[begin]);
            if (it == se.end()) {
                if (begin - end + 1 >  maxi) {
                    maxi = begin - end + 1;
                }
                se.insert(s[begin]);
                begin++;
            }
            else {
                se.erase(s[end]);
                end++;
                
            }
        }
        return maxi;
    }
};
