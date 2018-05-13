# https://leetcode.com/contest/weekly-contest-84/problems/find-and-replace-in-string/
class Solution(object):
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        R = sorted(zip(indexes, sources, targets), reverse = True)
        for e in R:
            idx, src, t = e[0], e[1], e[2]
            if S[idx: idx + len(src)] == src:
                # print(S[idx: idx + len(src)], src)
                S = S[:idx] + t + S[idx+len(src):]
        return S
