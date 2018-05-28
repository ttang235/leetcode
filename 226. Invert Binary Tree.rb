# https://leetcode.com/problems/invert-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {TreeNode}
def invert_tree(root)
    if root == nil
        return nil
    end
    root.left, root.right = invert_tree(root.right), invert_tree(root.left)
    return root
end
