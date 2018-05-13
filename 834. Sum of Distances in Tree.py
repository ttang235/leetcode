# https://leetcode.com/contest/weekly-contest-84/problems/sum-of-distances-in-tree/
class Solution(object):
    def process(self, e, g, m):
        if tuple(e) in m:
            return m[tuple(e)]
        if len(g[e[1]]) == 1:
            m[tuple(e)] = (1,0) # (node_num in subtree, total cost to reach all of them if starting from e[1])
            return (1,0)
        cost = 0
        num_nodes = 0
        for node in g[e[1]]:
            if node == e[0]:
                continue
            subtree_num_nodes, subtree_cost = self.process((e[1], node), g, m)
            cost += subtree_cost + subtree_num_nodes
            num_nodes += subtree_num_nodes
        m[tuple(e)] = (num_nodes + 1, cost)
        return (num_nodes + 1, cost)

    def sumOfDistancesInTree(self, N, edges):
        """
        :type N: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        m = {}
        g = [[] for i in range(N)]
        for e in edges:
            g[e[0]].append(e[1])
            g[e[1]].append(e[0])
        for e in edges:
            self.process(e, g, m)
            self.process(e[::-1], g, m)
        res = []
        for i in range(N):
            cost = 0
            for node in g[i]:
                subtree_num_nodes, subtree_cost = m[(i,node)]
                cost += subtree_cost + subtree_num_nodes
            res.append(cost)
        return res
