# https://leetcode.com/contest/weekly-contest-86/problems/split-array-into-fibonacci-sequence/
# Note: Enumerate all the possibilities of the first 2 numbers, and for each of
#   the possibilities, check its validity.
class Solution(object):
    BOUND = (1<<31) - 1
    MAX_DIGITS = len(str(BOUND))
    def find_res(self, s, x1, x2):
        res = [int(s[:x1]), int(s[x1:x1+x2])]
        cur = x1+x2
        while cur < len(s):
            nx = res[-2] + res[-1]
            if nx > self.BOUND:
                return []
            nx_str = str(nx)
            if len(s) - cur < len(nx_str) or nx_str != s[cur:cur+len(nx_str)]:
                return []
            cur += len(nx_str)
            res.append(nx)
        if cur == len(s):
            return res
        else:
            return []
    def splitIntoFibonacci(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        for x1 in range(1, self.MAX_DIGITS + 1):
            if x1 > len(S)-2:
                break
            if S[0] == '0' and x1 > 1:
                break
            if int(S[:x1]) > self.BOUND:
                break
            for x2 in range(1, self.MAX_DIGITS + 1):
                if x1+x2 > len(S)-1:
                    break
                if S[x1] == '0' and x2 > 1:
                    break
                if int(S[x1:x1+x2]) > self.BOUND:
                    break
                res = self.find_res(S, x1, x2)
                if len(res) > 0:
                    return res
        return []
