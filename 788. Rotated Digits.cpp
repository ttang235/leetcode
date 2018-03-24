// https://leetcode.com/problems/rotated-digits/description/
class Solution {
public:
    bool isGood(int x) {
        bool has_2569 = false;
        while(x) {
            int v = x % 10;
            if (v == 3 || v == 4 || v == 7) {
                return false;
            }
            if (v == 2 || v == 5 || v == 6 || v == 9) {
                has_2569 = true;
            }
            x /= 10;
        }
        return has_2569;
    }
    int rotatedDigits(int N) {
        int num = 0;
        for (int i = 1; i <= N; i++) {
            if (isGood(i)) {
                num++;
            }
        }
        return num;
    }
};
