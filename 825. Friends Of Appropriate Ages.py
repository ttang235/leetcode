class Solution(object):
    def numFriendRequests(self, ages):
        """
        :type ages: List[int]
        :rtype: int
        """
        cnt = [0] * 121
        for a in ages:
            cnt[a] += 1
        res = 0
        for i in range(1, 121):
            if cnt[i] > 1 and i > 14:
                res += cnt[i] * (cnt[i]-1)
            for j in range(i + 1, 121):
                if i > j * 0.5 + 7:
                    res += cnt[i] * cnt[j]
        return res
        
