public class Solution {
    public int RemoveDuplicates(int[] nums) {
        if (nums.Length == 0) return 0;
        
        int idx = 0;
        for (int i = 1; i < nums.Length; i++) {
            if (nums[i] != nums[idx]) {
                idx++;
                nums[idx] = nums[i];
            }
        }
        
        return idx + 1;
    }
}
