// https://leetcode.com/problems/image-overlap/description/
// This solution is pretty smart, not invented by me though..
// See https://leetcode.com/problems/image-overlap/discuss/130623/C++JavaPython-Straight-Forward
// This solution performs worse on the leetcode test cases, probably because
// there are some dense matrices in the cases. This solution is very efficient for sparse matrices.
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        unordered_map<int,int> m;
        vector<int> aa, bb;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if (A[i][j]) {
                    aa.push_back(i * 100 + j);
                }
                if (B[i][j]) {
                    bb.push_back(i * 100 + j);
                }
            }
        }
        for (auto v1 : aa) {
            for (auto v2 : bb) {
                m[v1-v2]++;
            }
        }
        int maxi = 0;
        for (auto& v : m) {
            maxi = max(maxi, v.second);
        }
        return maxi;
    }
};
