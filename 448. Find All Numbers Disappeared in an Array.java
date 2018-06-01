// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
// The idea is to put number cur to position cur-1, without overwriting the number
// in that position (by assigning it to tmp first).
// Though there are two loops, the time complexity is O(n), because each time
// the innermost part gets executed, one number is put to the right place; there
// are at most n numbers that need this operation.
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int cur = nums[i];
            int cur_pos = i;
            while (cur != cur_pos+1) {
                int tmp = nums[cur-1];
                nums[cur-1] = cur;
                cur_pos = cur - 1;
                cur = tmp;
            }
        }
        ArrayList<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i + 1) {
                res.add(i + 1);
            }
        }
        return res;
    }
}
