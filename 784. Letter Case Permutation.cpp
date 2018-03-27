// https://leetcode.com/problems/letter-case-permutation/description/
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if(S.size() == 0) {
            return {""};
        }
        auto res = letterCasePermutation(S.substr(1));
        if(isdigit(S[0])){
            for(auto & s : res) {
                s = S[0] + s;
            }
        } else {
            auto n = res.size();
            for(int i = 0; i < n; i++) {
                res.push_back(char(toupper(S[0])) + res[i]);
                res[i] = char(tolower(S[0])) + res[i];
            }
        }
        return res;
    }
};
