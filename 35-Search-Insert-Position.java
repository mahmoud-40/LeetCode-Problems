class Solution {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        int l = 0, r = n - 1;
        int mid = (l + r) / 2;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid] > target){
                r = mid - 1;
            }
            else if(nums[mid] < target) {
                l = mid + 1;
            }
            else{
                return mid;
            }
        }

        return l;
    }
}