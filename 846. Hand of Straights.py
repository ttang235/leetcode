# https://leetcode.com/contest/weekly-contest-87/problems/hand-of-straights/

class Solution(object):
    def isNStraightHand(self, hand, W):
        """
        :type hand: List[int]
        :type W: int
        :rtype: bool
        """
        if len(hand) % W != 0:
            return False
        m = {}
        L = []
        for v in hand:
            if v not in m:
                m[v] = 0
                L.append(v)
            m[v] += 1
        L.sort()
        for i in range(len(hand)/W):
            cur = L[-1]
            for v in range(cur,cur-W,-1):
                if v not in m:
                    return False
                m[v] -= 1
                if m[v] == 0:
                    if L[-1] != v:
                        return False
                    L.pop()
        return True
