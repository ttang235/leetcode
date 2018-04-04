// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
// m[s][i][j] is the minimum price to fly from i to j using at most s stops. -1 is used as infinity.
// m[s][i][j] is the min of the following 3 sets of values:
// 1. m[s-1][i][j]
// 2. price[i][x] + m[s-1][x][j] for each edge i --> x
// 3. price[x][j] + m[s-1][i][x] for each edge x --> j
// Time complexity: O(V^3 * E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<vector<int>>> m(K+1, vector<vector<int>>(n, vector<int>(n, -1)));
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>{}); // adj graph
        vector<vector<pair<int,int>>> g_in(n, vector<pair<int,int>>{}); // adj in-edge graph
        for(const auto & f : flights) {
            g[f[0]].push_back({f[1], f[2]});
            g_in[f[1]].push_back({f[0], f[2]});
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
                    for(auto& e : g_in[j]) {
                        if(m[s-1][i][e.first] == -1) {
                            continue;
                        }
                        if(m[s][i][j] == -1 || m[s][i][j] > m[s-1][i][e.first] + e.second) {
                            m[s][i][j] = m[s-1][i][e.first] + e.second;
                        }
                    }
                }
            }
        }
        return m[K][src][dst];
    }
};
