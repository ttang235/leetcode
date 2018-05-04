// https://leetcode.com/problems/baseball-game/description/
func removeC(a []string) []string {
    res := []string{}
    for _,v := range a {
        if v == "C" {
            if len(res) > 0 {
                res = res[:len(res)-1]
            }
        } else {
            res = append(res, v)
        }
    }
    return res
}
func calPoints(ops []string) int {
    arr := removeC(ops)
    vals := []int{}
    sum := 0
    for i,v := range arr {
        if v == "D" {
            vals = append(vals, vals[i-1] * 2)
        } else if v == "+" {
            vals = append(vals, vals[i-1] + vals[i-2])
        } else {
            c, _ := strconv.Atoi(v)
            vals = append(vals, c)
        }
        sum += vals[i]
    }
    return sum
}
