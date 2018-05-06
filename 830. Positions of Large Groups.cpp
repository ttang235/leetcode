// https://leetcode.com/contest/weekly-contest-83/problems/positions-of-large-groups/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        int i = 0, j = i+1;
        while (i < S.length()) {
            while(j < S.length() && S[j] == S[i]) {
                j++;
            }
            if (j - i >= 3) {
                res.push_back({i, j - 1});
            }
            i = j;
            j++;
        }
        return res;
    }
};
