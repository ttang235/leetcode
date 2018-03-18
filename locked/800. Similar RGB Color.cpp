// https://leetcode.com/contest/weekly-contest-76/problems/similar-rgb-color/
// One pitfall is whether you include 0x00.
// The code here can be further optimized (by a constant factor): instead of doing a linear search through 00 to ff, 
// we can do a binary search (organize the list into a tree-like structure). This reduces the num of searches
// from 16 to log2(16) = 4.
class Solution {
public:
    // c is like "aa"
    string closest(string c) {
        vector<int> cand = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
        vector<string> cand_s = {"00", "11", "22", "33", "44", "55", "66", "77", "88", "99", "aa", "bb", "cc", "dd", "ee", "ff"};
        int x;   
        std::stringstream ss;
        ss << std::hex << c;
        ss >> x;
        int mini = INT_MAX;
        int mini_idx = -1;
        for (int i = 0; i < cand.size(); i++) {
            int cur = (cand[i] - x) * (cand[i] - x);
            if(cur < mini) {
                mini = cur;
                mini_idx = i;
            }
        }
        return cand_s[mini_idx];
    }
    string similarRGB(string color) {
        return color[0] + closest(color.substr(1,2)) + closest(color.substr(3,2)) + closest(color.substr(5,2));
    }
};
