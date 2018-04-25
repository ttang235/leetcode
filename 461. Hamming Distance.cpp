// https://leetcode.com/problems/hamming-distance/description/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int val = x ^ y;
        int cnt = 0;
        while(val) {
            val &= (val - 1);
            cnt++;
        }
        return cnt;
    }
};
