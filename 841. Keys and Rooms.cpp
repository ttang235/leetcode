// https://leetcode.com/contest/weekly-contest-86/problems/keys-and-rooms/
// Note: similar to BFS.
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        q.push(0);
        unordered_set<int> keys;
        keys.insert(0);
        while(!q.empty()) {
           int cur = q.front();
            q.pop();
            for (auto k : rooms[cur]) {
                if (keys.count(k) == 0) {
                    keys.insert(k);
                    q.push(k);
                }
            }
        }
        return keys.size() == rooms.size();
    }
};
