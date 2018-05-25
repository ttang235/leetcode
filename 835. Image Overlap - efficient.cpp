// https://leetcode.com/problems/image-overlap/description/
// Convert each row into a int32, and use bit operations.
// Worst case O(N^4), but pretty fast in practice. 14ms on leetcode.
class Solution {
public:
    vector<int> conv(vector<vector<int>>& A) {
        vector<int> res;
        for (auto & vec : A) {
            int cur = 0;
            for (auto & val : vec) {
                cur <<= 1;
                cur |= val;
            }
            res.push_back(cur);
        }
        return res;
    }
    int count_bits(int v) { // https://en.wikipedia.org/wiki/Hamming_weight
        int cnt = 0;
        while (v) {
            cnt++;
            v &= (v-1);
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> aa = conv(A), bb = conv(B);
        int N = A.size();
        int maxi = 0;
        for (int r = -(N-1); r < N; r++) { // assume rows of B lies from row 0 to row N-1, and move A so that its first row ranges from row -(N-1) to row N-1
            for (int left_shift = N-1; left_shift >= -(N-1); left_shift--) {
                int overlap = 0;
                for (int i = 0; i < N; i++) { // when first row of A is at row r, the i-th row of A will be at r+i, so aa[i] will meet bb[r+i]
                    if (r + i < 0 || r + i >= N) {
                        continue;
                    }
                    if (left_shift >= 0) {
                        overlap += count_bits((aa[i] << left_shift) & bb[r + i]);
                    } else {
                        overlap += count_bits((aa[i] >> -left_shift) & bb[r + i]);
                    }
                }
                maxi = max(maxi, overlap);
            }
        }
        return maxi;
    }
};
