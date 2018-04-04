// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
// The idea is to iteratively update the best price for reaching each node (starting from src) using X hops, 
// up to K+1 hops away (i.e. using K hops) 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>{}); // pair<node, price>
        for(const auto & f : flights) {
            g[f[0]].push_back({f[1], f[2]});
        }
        vector<vector<int>> best(K+2, vector<int>(n, -1)); // best[i][j] is best price from src to j using exactly i hops (or equivalently, i-1 stops) 
        queue<pair<int,int>> q; // elements in queue are <#hops from src, destination node>. 
        // E.g. if 0 stop is need, that's one hop away 
        q.push({0,src}); // src to src is 0 hop away
        best[0][src] = 0;
        while(!q.empty()) {
            auto cur = q.front();
            auto cur_hop = cur.first, cur_node = cur.second;
            q.pop();
            if(cur_hop > K) { // we only need hop value up to K+1. If cur_hop is at least K+1, we need not explore more. 
                continue;
            }
            for(const auto& e : g[cur_node]) {
                auto next_node = e.first, price = e.second;
                if(best[cur_hop+1][next_node] == -1 || best[cur_hop+1][next_node] > best[cur_hop][cur_node] + price) {
                    best[cur_hop+1][next_node] = best[cur_hop][cur_node] + price;
                    q.push({cur_hop+1, next_node});
                }
            }
        }
        int best_price = -1;
        for(int i = 1; i <= K+1; i++) {
            if(best_price == -1 || (best[i][dst] != -1 && best_price > best[i][dst])) {
                best_price = best[i][dst];
            }
        }
        return best_price;
    }
};
