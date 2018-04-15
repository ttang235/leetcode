# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        cur = head
        cnt = 0
        g = set(G)
        while cur != None:
            found = False
            while cur != None and cur.val in g:
                if not found:
                    found = True
                    cnt += 1
                cur = cur.next
            if cur != None:
                cur = cur.next
        return cnt
