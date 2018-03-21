// https://leetcode.com/problems/find-eventual-safe-states/description/
// Idea: iteratively remove nodes that have 0 out-edge (terminal node). For all removed nodes, they either don't have
// an edge going out (terminal node), or they will go to terminal nodes.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> rev_graph(N, vector<int>{}); // reverse graph
        vector<int> out_deg(N, 0); // out degree of each node
        unordered_set<int> deg0; // set of nodes that have 0 out degree.
        vector<int> res; // final result
        // construct reverse graph, and get deg0.
        for(int i = 0; i < N; i++) {
            for(int j : graph[i]) {
                rev_graph[j].push_back(i);
            }
            out_deg[i] = graph[i].size();
            if (out_deg[i] == 0) {
                deg0.insert(i);
            }
        }
        // remove nodes that have 0 out degree.
        while(!deg0.empty()) {
            unordered_set<int> head_set;
            for(auto tail : deg0) {
                for (auto head : rev_graph[tail]) {
                    head_set.insert(head);
                }
            }
            unordered_set<int> deg0_new;
            // update graph
            for (int i : head_set) {
                vector<int> remain;
                for(int v : graph[i]) {
                    if (deg0.find(v) == deg0.end()) {
                        remain.push_back(v);
                    }
                }
                graph[i] = remain;
                if (remain.empty()) {
                    deg0_new.insert(i);
                }
            }
            // update rev_graph
            for (int i : deg0) {
                rev_graph[i].clear();
                res.push_back(i);
            }
            deg0 = deg0_new;
        };
        sort(res.begin(), res.end());
        return res;
    }
};
