# https://leetcode.com/problems/most-profit-assigning-work/description/
class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        """
        :type difficulty: List[int]
        :type profit: List[int]
        :type worker: List[int]
        :rtype: int
        """
        jobs = sorted(zip(difficulty, profit))
        for i in range(1, len(jobs)):
            if jobs[i][1] < jobs[i-1][1]:
                jobs[i] = jobs[i-1]
        worker.sort()
        ptr = 0
        res = 0
        for w in worker:
            while ptr < len(jobs) and w >= jobs[ptr][0]:
                ptr += 1
            if ptr > 0:
                res += jobs[ptr-1][1]
        return res
