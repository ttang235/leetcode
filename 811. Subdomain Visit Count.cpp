// https://leetcode.com/contest/weekly-contest-78/problems/subdomain-visit-count/
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for(auto s : cpdomains) {
            stringstream ss(s);
            int cnt;
            string d;
            ss >> cnt >> d;
            // cout << cnt << d;
            while(true) {
                m[d] += cnt;
                auto pos = d.find('.');
                // cout << "pos " << pos << endl;
                if(pos != string::npos) {
                    d = d.substr(pos+1);
                } else {
                    break;
                }
            }
        }
        vector<string> res;
        for(auto entry : m) {
            res.push_back(to_string(entry.second) + ' ' + entry.first);
        }
        return res;
    }
};
