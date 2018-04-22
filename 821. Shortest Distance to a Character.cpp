// https://leetcode.com/contest/weekly-contest-81/problems/shortest-distance-to-a-character/
// two scans: one forward, one backward
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> v(S.size(), S.size());
        int cur = -1;
        for(int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                cur = i;
                v[i] = 0;
            } else if (cur != -1) {
                v[i] = min(i - cur, v[i]);
            }
        }
        cur = S.size();
        for(int i = S.size() - 1; i >= 0; i--) {
            if (S[i] == C) {
                cur = i;
                v[i] = 0;
            } else if (cur != S.size()) {
                v[i] = min(cur - i, v[i]);
            }
        }
        return v;
    }
};
