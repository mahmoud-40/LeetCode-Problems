class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;

            if ((mid == 0 || nums[mid] > nums[mid - 1]) && 
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1])) {
                return mid;
            }
            
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l; // or return r, both are the same at this point
    }
};
