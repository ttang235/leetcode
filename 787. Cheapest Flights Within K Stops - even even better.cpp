// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
// Time complexity is about O(K * |V|^2)
// First round we add 1 element to queue
// Second round we add at most |V| elements to queue
// Third round we add at most |V|^2 elements to queue
// ...
// (K+1)-th round we add at most |V|^K elements to queue
// Looks like it's exponential: O(|V|^K)
// But actually each round the number "effective" elements added is upperbounded by |V|, because in that round, 
// there is only one best price for each node.
// So during K rounds, the number of effective nodes added to queue is K * |V| 
// For each node added to queue, the exploration cost is bounded by |V|.
// So the total cost is O(K * |V|^2).
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>{}); // pair<node, price>
        for(const auto & f : flights) {
            g[f[0]].push_back({f[1], f[2]});
        }
        vector<vector<int>> best(K+2, vector<int>(n, -1)); // best[i][j] is best price from src to j using exactly i hops (or equivalently, i-1 stops) 
        queue<tuple<int,int,int>> q; // elements in queue are <#hops from src, destination node, price>. 
        // E.g. if 0 stop is need, that's one hop away 
        q.push(make_tuple(0,src,0)); // src to src is 0 hop away, price is 0
        best[0][src] = 0;
        while(!q.empty()) {
            auto cur = q.front();
            auto cur_hop = get<0>(cur), cur_node = get<1>(cur), cur_price = get<2>(cur);
            q.pop();
            if(cur_hop > K) { // we only need hop value up to K+1. If cur_hop is at least K+1, we need not explore more. 
                continue;
            }
            if(cur_price > best[cur_hop][cur_node]) { // cur_price is no longer the best price, new node with better price must have been added, so no need to explore based on this node.
                continue;
            }
            for(const auto& e : g[cur_node]) {
                auto next_node = e.first, price = e.second;
                if(best[cur_hop+1][next_node] == -1 || best[cur_hop+1][next_node] > cur_price + price) {
                    best[cur_hop+1][next_node] = cur_price + price;
                    q.push(make_tuple(cur_hop+1, next_node, best[cur_hop+1][next_node]));
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
