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
    bool validTicTacToe(vector<string>& board) {
        auto s = board[0] + board[1] + board[2];
        int cnt_o = 0, cnt_x = 0;
        for(auto c : s) {
            if(c == 'O') {
                cnt_o++;
            } else if (c == 'X') {
                cnt_x++;
            }
        }
        char last = 'X';
        if(cnt_o == cnt_x) {
            if(cnt_o == 0) {
                return true;
            }
            last = 'O';
        } else if (cnt_x == cnt_o + 1) {
            last = 'X';
        } else {
            return false;
        }
        for(int i = 0; i < 9; i++) {
            if(s[i] == last) {
                s[i] = ' ';
                if(!isEnd(s)) {
                    return true;
                }
                s[i] = last;
            }
        }
        return false;
    }
};
