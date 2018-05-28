# https://leetcode.com/problems/detect-capital/description/

# @param {String} word
# @return {Boolean}
def detect_capital_use(word)
    if word.length == 1
        return true
    end
    if word[0].between?('a', 'z')
        for i in 1..word.length-1
            if !word[i].between?('a', 'z')
                return false
            end
        end
        return true
    else
        is_lower = word[1].between?('a', 'z')
        for i in 2..word.length-1
            if is_lower != word[i].between?('a', 'z')
                return false
            end
        end
        return true
    end
end
