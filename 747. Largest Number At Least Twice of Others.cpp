// https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int maxi = nums[0], second_maxi = nums[1];
        int maxi_idx = 0;
        if(maxi < second_maxi) {
            swap(maxi, second_maxi);
            maxi_idx = 1;
        }
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] > maxi) {
                second_maxi = maxi;
                maxi = nums[i];
                maxi_idx = i;
            } else if (nums[i] > second_maxi) {
                second_maxi = nums[i];
            }
        }
        if(maxi >= second_maxi * 2) {
            return maxi_idx;
        } else {
            return -1;
        }
    }
};
