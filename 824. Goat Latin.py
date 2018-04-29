https://leetcode.com/contest/weekly-contest-82/problems/goat-latin/
class Solution(object):
    def conv(self, w, idx):
        assert(len(w) > 0)
        if w[0].lower() in ['a', 'e', 'i', 'o', 'u']:
            return w + 'ma' + 'a' * (idx+1)
        else:
            return w[1:] + w[0] + 'ma' + 'a' * (idx+1)
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        ws = S.strip().split(' ')
        L = []
        for i, w in enumerate(ws):
            L.append(self.conv(w, i))
        return ' '.join(L)
