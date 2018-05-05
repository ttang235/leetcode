# https://leetcode.com/problems/reshape-the-matrix/description/
# @param {Integer[][]} nums
# @param {Integer} r
# @param {Integer} c
# @return {Integer[][]}
def matrix_reshape(nums, r, c)
    if nums.length * nums[0].length != r * c
        return nums
    end
    return nums.flatten.each_slice(c).to_a
end
