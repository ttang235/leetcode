class Solution {
public:
    bool is_magic(vector<vector<int>>& grid, int i, int j) {
        assert(i >= 0 && i+2 < grid.size());
        assert(j >= 0 && j+2 < grid[0].size());
        for (int d = 0; d < 3; d++) { // check rows
            if (grid[i+d][j] + grid[i+d][j+1] + grid[i+d][j+2] != 15) {
                return false;
            }
        }
        for (int d = 0; d < 3; d++) { // check columns
            if (grid[i][j+d] + grid[i+1][j+d] + grid[i+2][j+d] != 15) {
                return false;
            }
        }
        if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != 15 ||
            grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2] != 15 ) { // check diagonals
            return false;
        }
        // check 1-9 are all present
        vector<bool> v(10, false);
        for (int s = i; s <= i+2; s++) {
            for (int t = j; t <= j+2; t++) {
                v[grid[s][t]] = true;
            }
        }
        for (int i = 1; i < 10; i++) {
            if (!v[i]) {
                return false;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }
        int r = grid.size(), c = grid[0].size();
        int cnt = 0;
        for (int i = 0; i <= r-3; i++) {
            for (int j = 0; j <= c-3; j++) {
                if (is_magic(grid, i, j)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
