# https://leetcode.com/problems/max-area-of-island/description/

def dfs(grid, i, j)
    fail if grid.length == 0 || grid[0].length == 0
    fail if i < 0 || i >= grid.length
    fail if j < 0 || j >= grid[0].length
    fail if grid[i][j] != 1
    grid[i][j] = 0
    res = 1
    [[-1,0], [1,0], [0,1], [0,-1]].each do |(dx, dy)|
        if (i+dx).between?(0, grid.length-1) && (j+dy).between?(0, grid[0].length-1) && grid[i+dx][j+dy] == 1
            res += dfs(grid, i+dx, j+dy)
        end
    end
    return res
end

# @param {Integer[][]} grid
# @return {Integer}
def max_area_of_island(grid)
    maxi = 0
    for i in 0..grid.length-1
        for j in 0..grid[0].length-1
            if grid[i][j] == 1
                cur = dfs(grid, i, j)
                if maxi < cur
                    maxi = cur
                end
            end
        end
    end
    return maxi
end
