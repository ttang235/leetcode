# https://leetcode.com/problems/binary-number-with-alternating-bits/description/
# for a number X with bits like [0, 0, 0, a1, a2, a3, ..., an], the sufficient and necessary condition is 
# a1^a2 == 1, a2^a3 == 1, ..., a(n-1)^an == 1
# so it means X ^ (X >> 1) is something like 000111...111, i.e., it would be a power of 2 if you add 1 to it. 

# https://www.techotopia.com/index.php/Ruby_Operator_Precedence
# is power of 2. 2^0 also counts.
def is_power_of_2?(n)
    return (n & (n-1)) == 0  # can be written as "n & (n-1) == 0" as well. Parenthesis added for clarity.
end

# @param {Integer} n
# @return {Boolean}
def has_alternating_bits(n)
    val = (n ^ (n >> 1)) + 1
    return (val == 0 or is_power_of_2?(val)) # The parenthesis is somehow required, otherwise it reports 'void value expression' error
end
