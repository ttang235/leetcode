// https://leetcode.com/problems/all-paths-from-source-to-target/description/
// DP (with memorization). Recursion.
class Solution {
public:
    void allPath(vector<vector<int>>& graph, int cur, unordered_map<int, vector<vector<int>>>& paths) {
        if(cur == graph.size() - 1) {
            paths[cur] = {{cur}};
            return;
        }
        if(paths.find(cur) != paths.end()) {
            return;
        }
        for(int next : graph[cur]) {
            allPath(graph, next, paths);
            if(paths.find(next) != paths.end()) {
                for(vector<int>& path : paths[next]) {
                    vector<int> cur_path = {cur};
                    cur_path.insert(cur_path.end(), path.begin(), path.end());
                    paths[cur].push_back(cur_path);
                }
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int, vector<vector<int>>> paths;
        allPath(graph, 0, paths);
        return paths[0];
    }
};
