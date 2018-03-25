// https://leetcode.com/problems/number-of-lines-to-write-string/description/
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> len;
        for(char c : S) {
            len.push_back(widths[c - 'a']);
        }
        int sum = 0, lines = 0;
        for(int i : len) {
            sum += i;
            if (sum > 100) {
                sum = i;
                lines++;
            }
        }
        
        return {lines+1, sum};
    }
};
