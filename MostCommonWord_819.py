class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        ws = [w.lower() for w in re.findall(r"\b\w+\b", paragraph)]
        # print(ws)
        m = {}
        for w in ws:
            if w not in m:
                m[w] = 0
            m[w] += 1
        for b in banned:
            if b in m:
                m[b] = 0
        return max(m.iteritems(), key=operator.itemgetter(1))[0]
