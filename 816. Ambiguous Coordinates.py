class Solution(object):
    def allzero(self, s):
        return len([c for c in s if c != '0']) == 0
    def poss(self, s):
        if len(s) < 1:
            return []
        if len(s) == 1:
            return [s]
        if self.allzero(s):
            return []
        if s[0] == '0':
            if s[-1] == '0':
                return []
            else:
                return ['0.' + s[1:]]
        if s[-1] == '0':
            return [s]
        res = [s]
        for i in range(1,len(s)):
            res.append(s[:i] + '.' + s[i:])
        return res
    def combine(self, L1, L2):
        res = []
        for x in L1:
            for y in L2:
                res.append('(' + x + ', ' + y + ')')
        return res
    def ambiguousCoordinates(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        S = S[1:-1]
        # S[:pos], S[pos:]
        res = []
        for pos in range(1, len(S)):
            res.extend(self.combine(self.poss(S[:pos]), self.poss(S[pos:])))
        return res
        
