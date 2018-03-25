// https://leetcode.com/problems/unique-morse-code-words/description/
class Solution {
public:
    string trans(string w, vector<string>& morse) {
        string res;
        for (auto c : w) {
            res += morse[c - 'a'];
        }
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        for(auto w : words) {
            s.insert(trans(w, morse));
        }
        return s.size();
    }
};
