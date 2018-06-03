# https://leetcode.com/contest/weekly-contest-87/problems/backspace-string-compare/

class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        ss = ""
        tt = ""
        for c in S:
            if c == "#":
                if len(ss) > 0:
                    ss = ss[:-1]
            else:
                ss += c
        for c in T:
            if c == "#":
                if len(tt) > 0:
                    tt = tt[:-1]
            else:
                tt += c
        return ss == tt
