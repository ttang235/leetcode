// https://leetcode.com/problems/judge-route-circle/description/
class Solution {
public:
    bool judgeCircle(string moves) {
        int rl = 0, ud = 0;
        for(auto c : moves) {
            switch(c) {
                case 'R':
                    rl++;
                    break;
                case 'L':
                    rl--;
                    break;
                case 'U':
                    ud++;
                    break;
                case 'D':
                    ud--;
                    break;
            }
        }
        return rl == 0 && ud == 0;
    }
};
