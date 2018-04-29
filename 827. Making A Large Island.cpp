// https://leetcode.com/problems/making-a-large-island/description/
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int cur) {
        assert(grid[i][j] == 1);
        grid[i][j] = cur;
        for(const auto& d : vector<vector<int>>{{0,1}, {0,-1}, {1,0}, {-1,0}}) {
            int ni = i + d[0], nj = j + d[1];
            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1) { 
                // Initially I incorrectly used 'grid[i][j] == 1' in the above condition, which caused a hard-to-find bug.
                dfs(grid, ni, nj, cur);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int cur = 2;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, cur);
                    cur++;
                }
            }
        }
        vector<int> cnt(cur, 0);
        int maxi = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != 0) {
                    cnt[grid[i][j]]++;
                    if(cnt[grid[i][j]] > maxi) {
                        maxi = cnt[grid[i][j]];
                    }
                }
            }
        }
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> islands;
                    for(const auto& d : vector<vector<int>>{{0,1}, {0,-1}, {1,0}, {-1,0}}) {
                        int ni = i + d[0], nj = j + d[1];
                        if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] != 0) {
                            islands.insert(grid[ni][nj]);
                        }
                    }
                    int current = 1;
                    for(auto idx : islands) {
                        current += cnt[idx];
                    }
                    maxi = max(maxi, current);
                }
            }
        }
        return maxi;
    }
};
