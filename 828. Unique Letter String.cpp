// https://leetcode.com/contest/weekly-contest-83/problems/unique-letter-string/
// Hint: look at each individual char, and think about in which substrings will
//      this char be counted (obviously, in those substrings where this char is unique)
// Hint2: Look at the chars that are the same, e.g. 'A', and notice that they
//      can be processed together.
class Solution {
public:
    int uniqueLetterString(string S) {
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < S.length(); i++) {
            if (m.count(S[i]) == 0) {
                m[S[i]] = {-1};
            }
            m[S[i]].push_back(i);
        }
        int cnt = 0;
        for (auto& entry : m) {
            entry.second.push_back(S.length());
            const auto& vec = entry.second;
            for (int i = 1; i < vec.size() - 1; i++) {
                cnt += (vec[i] - vec[i-1]) * (vec[i+1] - vec[i]);
                cnt = cnt % 1000000007;
            }
        }
        return cnt;
    }
};
