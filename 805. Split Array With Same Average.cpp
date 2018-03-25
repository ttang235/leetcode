// https://leetcode.com/problems/split-array-with-same-average/description/
// 
// Explanation (how to turn this problem into subset sum problem): 
// Assume we can find such a move, e.g., we found the result to be B1, C1. B1 and C1 are disjoint. 
// The union of B1 and C1 equals A. mean(B1) = mean(C1).
// So sum(B1)/len(B1) = sum(C1)/len(C1) 
// <=> sum(B1)/len(B1) = sum(C1)/len(C1) = (sum(B1)+sum(C1))/(len(B1)+len(C1)) = sum(A)/len(A) = mean(A)
// <=> sum(B1)/len(B1) - mean(A) = 0
// <=> sum(B1) - len(B1)*mean(A) = 0
// this means if we subtract each value in B1 by mean(A), the sum of the values we get is 0.
// So this problem becomes: Subtract each value in A by its mean. Can we find a subset with sum being zero?
// https://en.wikipedia.org/wiki/Subset_sum_problem
// This is NP-complete.
//
// Solution: 
// 1. Subtract all values by the mean.
// 2. Split the values into two halves, and enumerate all subset sums in each (2^(N/2) values). 
// 3.1 If we can find a subset with sum being zero in either of these two halves, return true.
// 3.2 Otherwise, iterate through one of them, and try to find the opposite number in the other set.
// Time and space complexity are both 2^(N/2)
class Solution {
public:
    // Generate all subset sums. Return true early if found a non-empty subset with sum being 0. 
    // range is A[begin, end). If there are duplicates in the sums:
    // 1. duplicate 0: return true immediately
    // 2. duplicate with value being sum(A[begin,end)): then case 1 must happen, no need to worry about this.
    // 3. other duplicate values: don't care
    bool genSums(vector<int>& A, int begin, int end, unordered_set<int>& sums) {
        assert(begin >= 0 && begin <= end && end <= A.size());
        if (begin == end) {
            sums.insert(0); // empty set.
            return false;
        }
        if(genSums(A, begin+1, end, sums)){
            return true;
        }
        vector<int> cur;
        for(auto s : sums) {
            cur.push_back(s + A[begin]);
        }
        for(auto v : cur) {
            if (v == 0) {
                return true;
            }
            sums.insert(v);
        }
        return false;
    }
    bool splitArraySameAverage(vector<int>& A) {
        if (A.size() < 2) {
            return false;
        }
        int sumA = accumulate(A.begin(), A.end(), 0);
        for(auto &v : A) {
            v = A.size() * v - sumA;
        }
        int half = A.size()/2;
        int half_sum1 = accumulate(A.begin(), A.begin() + half, 0);
        if (half_sum1 == 0) {
            return true;
        }
        unordered_set<int> sums1, sums2;
        if(genSums(A, 0, half, sums1)){
            return true;
        }
        if(genSums(A, half, A.size(), sums2)){
            return true;
        }
        sums1.erase(half_sum1); // we want a strict subset
        sums1.erase(0); // we want a non-empty subset
        for(auto v1 : sums1) {
            if(sums2.find(-v1) != sums2.end()){
                return true;
            }
        }
        return false;
    }
};
