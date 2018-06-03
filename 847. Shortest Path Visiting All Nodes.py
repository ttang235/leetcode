# https://leetcode.com/contest/weekly-contest-87/problems/shortest-path-visiting-all-nodes/
# This is probably NP-hard. Use dynamic programming. The idea is:
# Define d(v, S) as the minimum distance we need to travel if we start from node v
# and traverse all nodes in node set S.
# d(v, S) = min(min_dist(v, u) + d(u, S-{u})) for u in S.
# min_dist can be done using bfs, because edge weights are 1.
# S can be represented in binary bits.
from collections import deque
class Solution(object):
    def fix_graph(self, graph):
        for i in range(len(graph)):
            for n in graph[i]:
                if i not in graph[n]:
                    graph[n].append(i)
    def bfs(self, graph, start, stop, mm):
        if (start,stop) in mm:
            return mm[(start,stop)]
        q = deque([(start,0)])
        s = set([start])
        while len(q) > 0:
            cur = q.popleft()
            for n in graph[cur[0]]:
                if n == stop:
                    mm[(start,stop)] = cur[1]+1
                    mm[(stop,start)] = cur[1]+1
                    return cur[1] + 1
                if n not in s:
                    s.add(n)
                    q.append((n, cur[1]+1))
        raise Exception("Unexpected")
    def d(self, graph, v, S, m, m_bfs):
        # print(v, "{0:b}".format(S))
        if S == 0:
            return 0
        if (v,S) in m:
            return m[(v,S)]
        mini = 1000000
        for i in range(12):
            if ((1 << i) & S) != 0:
                cur = self.bfs(graph, v, i, m_bfs) + self.d(graph, i, S ^ (1 << i), m, m_bfs)
                mini = min(mini, cur)
        m[(v,S)] = mini
        return mini
    def shortestPathLength(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        self.fix_graph(graph)
        m = {}
        m_bfs = {}
        N = len(graph)
        S = (1 << N) - 1
        mini = 1000000
        for i in range(N):
            mini = min(mini, self.d(graph, i, S ^ (1 << i), m, m_bfs))
        return mini
