class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
    
    int helper(vector<int>& nums, int index, int current_xor) {
        if (index == nums.size()) {
            return current_xor;
        }
        
        int include = helper(nums, index + 1, current_xor ^ nums[index]);
        
        int exclude = helper(nums, index + 1, current_xor);
        
        return include + exclude;
    }
};