# @param {Integer[][]} matrix
# @return {Boolean}
def is_toeplitz_matrix(matrix)
    for i in 0..matrix.length-1
        # deal with (i,0)
        cur = matrix[i][0]
        for j in i+1..matrix.length-1
            if j-i >= matrix[0].length
                break
            end
            if matrix[j][j-i] != cur
                return false
            end
        end
    end
    for j in 1..matrix[0].length-1
        # deal with (0,j)
        cur = matrix[0][j]
        for i in 1..matrix.length-1
            if i+j >= matrix[0].length
                break
            end
            if matrix[i][i+j] != cur
                return false
            end
        end
    end
    return true
end
