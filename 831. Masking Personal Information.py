# https://leetcode.com/contest/weekly-contest-83/problems/masking-personal-information/
class Solution(object):
    def maskPII(self, S):
        """
        :type S: str
        :rtype: str
        """
        if '@' in S:
            arr = S.split('@')
            return arr[0][0].lower() + '*****' + arr[0][-1].lower() + '@' + arr[1].lower()
        d = [x for x in S if x.isdigit()]
        local = '***-***-' + ''.join(d[-4:])
        if len(d) > 10:
            return '+' + '*' * (len(d) - 10) + '-' + local
        else:
            return local
