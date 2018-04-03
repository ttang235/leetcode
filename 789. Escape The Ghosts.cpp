// https://leetcode.com/problems/escape-the-ghosts/description/
// It can be proved that 
// "ghost-target manhattan distance is no larger than you-target manhattan distance" <==> "the ghost can catch you"
class Solution {
public:
    int dist(int x1, int y1, int x2, int y2) { // manhattan distance
        return max(x1,x2)-min(x1,x2) + max(y1,y2)-min(y1,y2);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int d = dist(0, 0, target[0], target[1]);
        for(auto g : ghosts) {
            if(dist(g[0], g[1], target[0], target[1]) <= d) {
                return false;
            }
        }
        return true;
    }
};
