// https://leetcode.com/problems/custom-sort-string/description/

class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> cnt(26, 0);
        for(auto c : T) {
            cnt[c - 'a']++;
        }
        string res;
        for(auto c : S) {
            res += string(cnt[c-'a'], c);
            cnt[c-'a'] = 0;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0) {
                res += string(cnt[i], char('a' + i));
            }
        }
        return res;
    }
};
