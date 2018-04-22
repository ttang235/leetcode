// https://leetcode.com/contest/weekly-contest-81/problems/card-flipping-game/
// if number A is a good number, the card must not have A on both sides. Given this, if number A doesn't appear on any card that has 
// both sides being A, then A is a candidate. Find the min among these candidates.
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> s1, s2;
        for(int i = 0; i < fronts.size(); i++) {
            if(fronts[i] == backs[i]) {
                s2.insert(fronts[i]);
            } else {
                s1.insert(fronts[i]);
                s1.insert(backs[i]);
            }
        }
        int mini = 20000;
        for(auto v : s1) {
            if(s2.count(v) == 0) {
                mini = min(mini, v);
            }
        }
        return mini == 20000 ? 0 : mini;
    }
};
