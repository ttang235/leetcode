// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
// counting strategy: how many subarrays starting at index i satisfy the requirement? i = 0, 1, .., len-1
// Time complexity: O(n)
class Solution {
public:
    int count(vector<int>& v, int L) {
        if(v.empty()) {
            return 0;
        }
        int len = v.size();
        vector<int> next(len, INT_MAX); 
        // next[i] store the index of first value that is >= L in range v[i...end] (including i)
        if(v[len - 1] >= L) {
            next[len - 1] = len - 1;
        }
        for(int i = len - 2; i >= 0; i--) {
            if(v[i] >= L) {
                next[i] = i;
            } else {
                next[i] = next[i+1];
            }
        }
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            if(next[i] != INT_MAX) {
                cnt += len - next[i];
            } else {
                break;
            }
        }
        return cnt;
    }
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        vector<int> v;
        int cnt = 0;
        for(auto x : A) {
            if(x > R) {
                cnt += count(v, L);
                v.clear();
            } else {
                v.push_back(x);
            }
        }
        cnt += count(v, L);
        return cnt;
    }
};
