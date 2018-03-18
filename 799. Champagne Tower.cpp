// https://leetcode.com/problems/champagne-tower/description/
// Space usage can be optimized further (from n^2 to n).
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> x(101, vector<double>(101, 0));
        x[1][1] = poured;
        for (int i = 2; i <= query_row + 1; i++) {
            for (int j = 1; j <= query_glass + 1; j++) {
                x[i][j] = max(0.0, (x[i-1][j-1]-1)/2) + max(0.0, (x[i-1][j]-1)/2);
            }
        }
        return min(1.0, x[query_row+1][query_glass+1]);
    }
};
