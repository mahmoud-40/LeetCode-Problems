class Solution {
public:
    vector<vector<int>> dp;

    int fun(vector<int>& nums, int i, int k, int target) {
        if (i == nums.size()) {
            return (k == target) ? 1 : 0;
        }

        if (dp[i][k + 1000] != -1) {
            return dp[i][k + 1000];
        }

        int include = fun(nums, i + 1, k + nums[i], target);
        int exclude = fun(nums, i + 1, k - nums[i], target);

        return dp[i][k + 1000] = include + exclude;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size() + 1, vector<int>(2001, -1)); 
        return fun(nums, 0, 0, target);
    }
};