// https://leetcode.com/problems/distribute-candies/description/
func distributeCandies(candies []int) int {
    m := map[int]bool{}
    for _, v := range candies {
        m[v] = true
    }
    res := len(m)
    if res > len(candies) / 2 {
        res = len(candies) / 2
    }
    return res
}
