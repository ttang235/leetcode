// https://leetcode.com/problems/number-of-matching-subsequences/description/
// Hint: build a "char -> index" map for the string S; then the problem becomes 'for each char in a word, find an index for it'
// we can use binary search for finding the index. 
// Time complexity: O(|S| + |num_of_words| * |word_length| * log|S|)
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char,vector<int>> m;
        for (int i = 0; i < S.size(); i++) {
            m[S[i]].push_back(i);
        }
        int cnt = 0;
        for (auto& w : words) {
            int cur = -1;
            bool is_subseq = true;
            for (auto c : w) {
                auto it = upper_bound(m[c].begin(), m[c].end(), cur);
                if (it == m[c].end()) {
                    is_subseq = false;
                    break;
                } else {
                    cur = *it;
                }
            }
            if (is_subseq) {
                cnt++;
            }
        }
        return cnt;
    }
};
