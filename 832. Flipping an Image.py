# https://leetcode.com/contest/weekly-contest-84/problems/flipping-an-image/
class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        for x in A:
            res.append([1 - v for v in reversed(x)])
        return res
