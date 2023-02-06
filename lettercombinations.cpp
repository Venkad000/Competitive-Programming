class Solution {
public:
    int n;
    vector<string>result;
    string current;
    unordered_map<string , vector<string>>umap;
    string digit;
    void backtrack(int len) {
        if (len == n) {
            result.push_back(current);
        }
        else {
            for (int i = 0; i < umap[digit.substr(len,1)].size();i++) {
                current.append(umap[digit.substr(len,1)][i]);
                backtrack(len+1);
                current.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return vector<string>{};
        }
        n = digits.length();
        digit = digits;
        umap["2"] = vector<string>{"a","b","c"};
        umap["3"] = vector<string>{"d","e","f"};
        umap["4"] = vector<string>{"g","h","i"};
        umap["5"] = vector<string>{"j","k","l"};
        umap["6"] = vector<string>{"m","n","o"};
        umap["7"] = vector<string>{"p","q","r","s"};
        umap["8"] = vector<string>{"t","u","v"};
        umap["9"] = vector<string>{"w","x","y", "z"};

        backtrack(0);
        return result;
    }
};
