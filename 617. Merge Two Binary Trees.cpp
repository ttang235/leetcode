// https://leetcode.com/problems/merge-two-binary-trees/description/
// This solution assumes we don't modify the input trees.
// The solution that allows in-place modification is simpler/shorter.
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
    TreeNode* copy(TreeNode* t) {
        if (t == NULL) {
            return NULL;
        }
        TreeNode *c = new TreeNode(t->val);
        c->left = copy(t->left);
        c->right = copy(t->right);
        return c;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) {
            if(t2 == NULL) {
                return NULL;
            } else {
                return copy(t2);
            }
            return t2;
        } else {
            if(t2 == NULL) {
                return copy(t1);
            } else {
                TreeNode* c = new TreeNode(t1->val + t2->val);
                c->left = mergeTrees(t1->left, t2->left);
                c->right = mergeTrees(t1->right, t2->right);
                return c;
            }
        }
    }
};
