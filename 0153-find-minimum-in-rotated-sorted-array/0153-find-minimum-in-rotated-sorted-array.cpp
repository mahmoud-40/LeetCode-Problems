class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        int mn = nums[0]; 
        
        while (left <= right) {
            if (nums[left] <= nums[right]) {
                mn = min(mn, nums[left]);
                break;
            }
            
            int mid = left + (right - left) / 2;
            mn = min(mn, nums[mid]);
            
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return mn;
    }
};