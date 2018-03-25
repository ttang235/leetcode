// https://leetcode.com/contest/weekly-contest-76/problems/minimum-swaps-to-make-sequences-increasing/
// This is dynamic programming. 
// The optimal solution for A[0]..A[i] and B[0]..B[i] depends only on the optimal solution for A[0]..A[i-1] and B[0]..B[i-1]
// The critical part is that the status of the tail (whether A[i-1] and B[i-1] is swapped) needs to be memorized.
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<vector<int>> s(2, vector<int>(n, n));
        s[0][0] = 0; // s[0][i] refers to the minimum swaps needed for A[0]..A[i] and B[0]..B[i] when A[i] and B[i] is *not* swapped; s[1][i] refers to the minimum swaps needed for A[0]..A[i] and B[0]..B[i] when A[i] and B[i] *is* swapped;
        s[1][0] = 1;
        for(int i = 1; i < n; i++) {
            if(A[i-1] < A[i] && B[i-1] < B[i]) {
                s[0][i] = s[0][i-1];
                s[1][i] = s[1][i-1] + 1;
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                s[0][i] = min(s[0][i], s[1][i-1]);
                s[1][i] = min(s[1][i], s[0][i-1] + 1);
            }
        }
        return min(s[0][n-1], s[1][n-1]);
    }
};
