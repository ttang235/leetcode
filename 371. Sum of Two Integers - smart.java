// a smart solution from here: https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently
// The core idea: the carry part is in (a&b) << 1, while the non-carry part is a^b
class Solution {
    public int getSum(int a, int b) {
        return b == 0 ? a : getSum(a^b, (a&b) << 1);
    }
}
