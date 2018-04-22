// https://leetcode.com/problems/short-encoding-of-words/description/
// reverse words, use trie
class Solution {
public:
    class Node {
        public:
        Node() {
            for(int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
        Node* child[26];
    };
    void insert(Node* root, string w) {
        auto cur = root;
        for(auto c : w) {
            if(cur->child[c-'a'] == NULL) {
                cur->child[c-'a'] = new Node();
            }
            cur = cur->child[c-'a'];
        }
    }
    int sum_depth(Node *root, int cur_depth) {
        if(root == NULL) {
            return 0;
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            res += sum_depth(root->child[i], cur_depth+1);
        }
        if(res == 0) { // leaf
            return cur_depth;
        }
        return res;
    }
    int minimumLengthEncoding(vector<string>& words) {
        Node* root = new Node();
        for(string w : words) {
            reverse(w.begin(), w.end());
            insert(root, w);
        }
        return sum_depth(root, 1);
    }
};
