https://leetcode.com/problems/jewels-and-stones/description/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> JJ;
        for(auto c : J) {
            JJ.insert(c);
        }
        int cnt = 0;
        for(auto c : S) {
            if(JJ.count(c) > 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
