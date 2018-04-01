// https://leetcode.com/contest/weekly-contest-78/problems/expressive-words/
class Solution {
public:
    vector<pair<char,int>> conv(string s) {
        vector<pair<char,int>> res;
        if(s.empty()) {
            return res;
        }
        auto cur = s[0];
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == cur) {
                cnt++;
            } else {
                res.push_back({cur,cnt});
                cnt = 1;
                cur = s[i];
            }
        }
        res.push_back({cur,cnt});
        return res;
    }
    int expressiveWords(string S, vector<string>& words) {
        auto ref = conv(S);
        int cnt = 0;
        for(auto s : words) {
            bool ok = true;
            auto ss = conv(s);
            if(ss.size() != ref.size()) {
                ok = false;
            }
            for(int i = 0; i < ss.size(); i++) {
                if(ss[i].first != ref[i].first) {
                    ok = false;
                }
                if(ss[i].second > ref[i].second) {
                    ok = false;
                }
                if(ss[i].second < ref[i].second && ref[i].second < 3) {
                    ok = false;
                }
            }
            if(ok) {
                cnt++;
            }
        }
        return cnt;
    }
};
