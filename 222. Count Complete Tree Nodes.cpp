// https://leetcode.com/problems/count-complete-tree-nodes/description/
// Note: do binary search on the last level. Notice that the binary representation
// of a number can be used to tell us how to go from the root to the leaves.
// Time complexity: O(log(n) * log(n))
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root) {
        int d = 0;
        while (root) {
            d++;
            root = root->left;
        }
        return d;
    }
    bool exist(TreeNode* root, int path) {
        int mask = 0x40000000; // assume tree depth won't exceed 31
        while ((mask & path) == 0) {
            mask >>= 1;
        }
        mask >>= 1;
        while (mask) {
            if (root == NULL) {
                return false;
            }
            if (mask & path) {
                root = root->right;
                // cout << "mask: " << mask << ", move right\n";
            } else {
                root = root->left;
                // cout << "mask: " << mask << ", move left\n";
            }
            mask >>= 1;
        }
        return root != NULL;
    }

    int countNodes(TreeNode* root) {
        int d = depth(root);
        if (d <= 1) {
            return d;
        }
        int start = 1 << (d-1);
        int finish = (1<<d) - 1;
        if (exist(root, finish)) {
            return finish;
        }
        while (start + 1 < finish) {
            int mid = (start + finish) / 2;
            // cout << "mid: " << mid << ", start: " << start << ", finish: " << finish << endl;
            if (exist(root, mid)) {
                start = mid;
            } else {
                finish = mid;
            }
        }
        return start;
    }
};
