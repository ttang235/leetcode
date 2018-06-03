# https://leetcode.com/contest/weekly-contest-87/problems/longest-mountain-in-array/

class Solution(object):
    def longestMountain(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if len(A) <= 2:
            return 0
        left = [0]
        for i in range(1,len(A)):
            if A[i] > A[i-1]:
                left.append(left[i-1])
            else:
                left.append(i)
        right = [len(A)-1]*len(A)
        for i in range(len(A)-2, 0, -1):
            if A[i] > A[i+1]:
                right[i] = right[i+1]
            else:
                right[i] = i
        maxi = 0
        for i in range(1, len(A)-1):
            if right[i] != i and left[i] != i:
                maxi = max(maxi, right[i] - left[i] + 1)
        return maxi
