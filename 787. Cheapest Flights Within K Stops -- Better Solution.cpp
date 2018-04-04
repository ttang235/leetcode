// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
// in-edge graph is not needed. To get m[s][i][j], we know that there must be an out-edge originating from i, so
// enumerating the out-edges is good enough. This cut computation by 50%.
// Time complexity: O(V^3 * E). V: #nodes; E: #edges.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<vector<int>>> m(K+1, vector<vector<int>>(n, vector<int>(n, -1)));
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>{});
        for(const auto & f : flights) {
            g[f[0]].push_back({f[1], f[2]});
            m[0][f[0]][f[1]] = f[2];
        }
        for(int s = 1; s <= K; s++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    m[s][i][j] = m[s-1][i][j];
                    for(auto& e : g[i]) {
                        if(m[s-1][e.first][j] == -1) {
                            continue;
                        }
                        if(m[s][i][j] == -1 || m[s][i][j] > m[s-1][e.first][j] + e.second) {
                            m[s][i][j] = m[s-1][e.first][j] + e.second;
                        }
                    }
                }
            }
        }
        return m[K][src][dst];
    }
};
