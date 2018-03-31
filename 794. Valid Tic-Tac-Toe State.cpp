// https://leetcode.com/problems/valid-tic-tac-toe-state/description/
class Solution {
public:
    bool isEnd(string s) {
        if(s.substr(0,3) == "OOO" || s.substr(3,3) == "OOO" || s.substr(6,3) == "OOO" ||
          s.substr(0,3) == "XXX" || s.substr(3,3) == "XXX" || s.substr(6,3) == "XXX"){
            return true;
        }
        if(s[0] == s[4] && s[4] == s[8] && s[0] != ' ') {
            return true;
        }
        if(s[2] == s[4] && s[4] == s[6] && s[2] != ' ') {
            return true;
        }
        if(s[0] == s[3] && s[3] == s[6] && s[0] != ' ') {
            return true;
        }
        if(s[1] == s[4] && s[4] == s[7] && s[1] != ' ') {
            return true;
        }
        if(s[2] == s[5] && s[5] == s[8] && s[2] != ' ') {
            return true;
        }
        return false;
    }
    unordered_set<string> nextLayer(unordered_set<string>& cur_layer, char c) {
        unordered_set<string> res;
        for(auto cur : cur_layer) {
            if(isEnd(cur)) {
                continue;
            }
            for(int i = 0; i < cur.size(); i++) {
                if(cur[i] == ' ') {
                    auto n = cur;
                    n[i] = c;
                    res.insert(n);
                }
            }    
        }
        return res;
    }
    unordered_set<string> genAll() {
        unordered_set<string> all;
        string cur = string(9, ' ');
        unordered_set<string> cur_layer = {cur};
        char cur_c = 'X';
        all.insert(cur);
        for(int i = 0; i < 9; i++) {
            auto next_set = nextLayer(cur_layer, cur_c);
            for(auto x : next_set) {
                all.insert(x);
            }
            cur_layer = next_set;
            cur_c = cur_c == 'X' ? 'O' : 'X';
        }
        return all;
    }
    bool validTicTacToe(vector<string>& board) {
        auto all = genAll();
        if(all.count(board[0]+board[1]+board[2]) == 1) {
            return true;
        }
        return false;
    }
};
