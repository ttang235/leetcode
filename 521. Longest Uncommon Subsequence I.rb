# https://leetcode.com/problems/longest-uncommon-subsequence-i/description/

# @param {String} a
# @param {String} b
# @return {Integer}
def find_lu_slength(a, b)
    if a.length != b.length
        return a.length > b.length ? a.length : b.length
    end
    if a == b
        return -1
    end
    return a.length
end
