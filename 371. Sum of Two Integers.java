https://leetcode.com/problems/sum-of-two-integers/description/

class Solution {
    public int getSum(int a, int b) {
        int res = 0, carry = 0;
        for (int i = 0; i < 32; i++) {
            int aa = (a >> i) & 1;
            int bb = (b >> i) & 1;
            res |= (aa ^ bb ^ carry) << i;
            if (aa == 1 && bb == 1 || aa == 1 && carry == 1 || bb == 1 && carry == 1) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        return res;
    }
}
