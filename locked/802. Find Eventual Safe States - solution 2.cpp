// dfs

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& status, int cur, vector<bool>& path) {
        // cur is visited
        if(status[cur] == 1) { // visited, not lead to loop
            if(path[cur]) { // on current path
                status[cur] = 2;
                return true;
            }
            return false;
        } else if (status[cur] == 2) {
            return true;
        }
        // cur is unvisited, surely not on path
        status[cur] = 1;
        path[cur] = true;
        bool res = false;
        for(int next : graph[cur]) {
            if(dfs(graph, status, next, path)) {
                status[cur] = 2;
                res = true;
            }
        }
        path[cur] = false;
        return res;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> status(N, 0); // 0: not visited; 1: visited, not lead to loop; 2: visited, lead to loop;
        vector<bool> path(N, false); // 
        for(int i = 0; i < N; i++) {
            dfs(graph, status, i, path);
        }
        vector<int> res;
        for(int i = 0; i < N; i++) {
            if(status[i] == 1) {
                res.push_back(i);
            }
        }
        return res;
    }
};
