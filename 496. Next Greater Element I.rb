# https://leetcode.com/problems/next-greater-element-i/description/
# This is a linear-time solution using 'next' array (similar to the idea in KMP)
# The proof of linearity: See https://sketch.io/render/sk-fa57c9592ef4495492c98405eddf91fb.jpeg (or images/496.png)
# To determine the next greater value for nums[1], nums[2], nums[3], nums[4], you only need one comparison (the black arrows)
# To determine the next greater value for nums[0], you need to trace the 'next' array all the way to num[6] and 
#   do 5 comparisons (the blue arrows)
# If there were a value before nums[0] (not shown in that graph), say X, there are two cases:
#   1. X < nums[0], then only one comparison is needed to determine the next greater value for it (just nums[0])
#   2. X > nums[0], then we can use 'next' array to skip the comparisons done in the blue arrows
# In summary, we only need to do two comparisons per element in the array. So it's linear.

# @param {Integer[]} find_nums
# @param {Integer[]} nums
# @return {Integer[]}
def next_greater_element(find_nums, nums)
    len = nums.length
    next_index = [len] * len
    for i in (len-2).downto(0)
        j = i + 1
        while j < len and nums[i] > nums[j]
            j = next_index[j]
        end
        next_index[i] = j
    end
    v2i = {}
    nums.each_with_index { |val, index| v2i[val] = index }
    res = []
    find_nums.each do |val|
        ni = next_index[v2i[val]]
        res.push(ni == len ? -1 : nums[ni])
    end
    return res  
end
