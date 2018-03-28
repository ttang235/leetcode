// https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/
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
    vector<int> maxMinAndMinDiff(TreeNode * root) { // return a vector with 3 elements: max, min, and min_diff
        if (root == NULL) {
            return {};
        }
        auto left = maxMinAndMinDiff(root->left);
        auto right = maxMinAndMinDiff(root->right);
        int maxi = root->val, mini = root->val, mindiff = INT_MAX;
        if(!right.empty()) {
            maxi = right[0];
            mindiff = min(mindiff, right[2]);
            mindiff = min(mindiff, right[1] - root->val);
        }
        if (!left.empty()) {
            mini = left[1];
            mindiff = min(mindiff, left[2]);
            mindiff = min(mindiff, root->val - left[0]);
        }
        return {maxi, mini, mindiff};
    }
    int minDiffInBST(TreeNode* root) {
        return maxMinAndMinDiff(root)[2];
    }
};
