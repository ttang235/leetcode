// https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int cur = -1, i = 0;
        while(i < bits.size()) {
            if(bits[i] == 1) {
                cur = 2;
                i += 2;
            } else {
                cur = 1;
                i++;
            }
        }
        return cur == 1;
    }
};
