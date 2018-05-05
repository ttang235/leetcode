func islandPerimeter(grid [][]int) int {
    p := 0
    for i := 0; i < len(grid); i++ {
        for j := 0; j < len(grid[0]); j++ {
            if grid[i][j] == 0 {
                continue
            }
            cur := 4
            if i - 1 >= 0 && grid[i-1][j] == 1 {
                cur--
            }
            if i + 1 < len(grid) && grid[i+1][j] == 1 {
                cur--
            }
            if j - 1 >= 0 && grid[i][j-1] == 1 {
                cur--
            }
            if j + 1 < len(grid[0]) && grid[i][j+1] == 1 {
                cur--
            }
            p += cur
        }
    }
    return p
}
