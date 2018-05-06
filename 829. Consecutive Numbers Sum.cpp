// https://leetcode.com/contest/weekly-contest-83/problems/consecutive-numbers-sum/
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        double bound = sqrt(N*2.0);
        int cnt = 0;
        for (int i = 1; i < bound; i++) {
            if ((2 * N) % i != 0) {
                continue;
            }
            int v = 2 * N / i;
            if (v > i && (v - (i-1)) % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
