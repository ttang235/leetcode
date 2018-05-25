// https://leetcode.com/problems/image-overlap/description/
// A straight-forward way: Enumerating all the possible positions of the upperleft corner of A.
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int maxi = 0;
        int N = A.size();
        for (int x = -(N-1); x < N; x++) {
            for (int y = -(N-1); y < N; y++) {
                int overlap = 0;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (x + i < 0 || x + i >= N || y + j < 0 || y + j >= N || A[i][j] == 0 || B[x+i][y+j] == 0) {
                            continue;
                        }
                        overlap++;
                    }
                }
                maxi = max(maxi, overlap);
            }
        }
        return maxi;
    }
};
