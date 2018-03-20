// https://leetcode.com/problems/rotate-string/description/
// Brutal..
class Solution {
public:
    string rotate(string A, int n) {
        assert(n >= 0 && n < A.size());
        return A.substr(n) + A.substr(0, n);
    }
    bool rotateString(string A, string B) {
        if (A == B) {
            return true;
        }
        for (int i = 1; i < A.size(); i++) {
            if (B == rotate(A, i)) {
                return true;
            }
        }
        return false;
    }
};
