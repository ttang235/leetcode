# https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Float[]}
def average_of_levels(root)
    q = [root]
    res = []
    len = q.length
    while len > 0
        sum = 0.0
        for i in 0..len-1
            sum += q[i].val
            if q[i].left != nil
                q.push(q[i].left)
            end
            if q[i].right != nil
                q.push(q[i].right)
            end
        end
        res.push(sum / len)
        q.shift(len)
        len = q.length
    end
    return res
end
