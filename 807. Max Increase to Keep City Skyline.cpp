// https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> left, top;
        int r = grid.size(), c = grid[0].size();
        for(int i = 0; i < r; i++) {
            int maxi = 0;
            for (int j = 0; j < c; j++) {
                maxi = max(maxi, grid[i][j]);
            }
            left.push_back(maxi);
        }
        for(int j = 0; j < c; j++) {
            int maxi = 0;
            for (int i = 0; i < r; i++) {
                maxi = max(maxi, grid[i][j]);
            }
            top.push_back(maxi);
        }
        int res = 0;
        for(int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res += min(left[i], top[j]) - grid[i][j];
            }
        }
        return res;
    }
};
