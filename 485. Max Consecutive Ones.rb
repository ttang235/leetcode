# https://leetcode.com/problems/max-consecutive-ones/description/
# New knowledge: in Ruby, function collect is the same as map, and inject is the same as reduce
# @param {Integer[]} nums
# @return {Integer}
def find_max_consecutive_ones(nums)
    ones = nums.map{ |x| x.to_s() }.join('').split('0')
    return ones.length == 0 ? 0 : ones.map{ |x| x.length }.max()
end
