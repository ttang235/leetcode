# https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/submissions/1
def count_bits(n)
    cnt = 0
    while n != 0
        n &= (n-1)
        cnt += 1
    end
    return cnt
end

# @param {Integer} l
# @param {Integer} r
# @return {Integer}
def count_prime_set_bits(l, r)
    res = 0
    for v in l..r
        cnt = count_bits(v)
        if cnt == 2 || cnt == 3 || cnt == 5 || cnt == 7 || cnt == 11 || cnt == 13 || cnt == 17 || cnt == 19
            res += 1
        end
    end
    return res
end
