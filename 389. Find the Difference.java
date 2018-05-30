// https://leetcode.com/problems/find-the-difference/description/
class Solution {
    public char findTheDifference(String s, String t) {
        char[] ss = s.toCharArray(), tt = t.toCharArray();
        Arrays.sort(ss);
        Arrays.sort(tt);
        for (int i = 0; i < ss.length; i++) {
            if (ss[i] != tt[i]) {
                return tt[i];
            }
        }
        return tt[tt.length - 1];
    }
}
