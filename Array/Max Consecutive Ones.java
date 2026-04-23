package Array;

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0;
        int maxone = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                cnt++;
                maxone = Math.max(maxone, cnt);
            } else {
                cnt = 0;
            }
        }
        return maxone;
    }
}