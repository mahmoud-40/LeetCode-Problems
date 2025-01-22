class Solution {
public:
    vector<vector<int>> dp;

    int LIS(int idx, int prev, vector<int> &nums) {
        if (idx == nums.size()) {
            return 0;
        }

        if (dp[idx][prev + 1] != -1) {
            return dp[idx][prev + 1];
        }

        int leave = LIS(idx + 1, prev, nums);
        
        int take = 0;
        if (prev == -1 || nums[idx] > nums[prev]) {
            take = 1 + LIS(idx + 1, idx, nums);
        }

        return dp[idx][prev + 1] = max(leave, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), vector<int>(nums.size() + 1, -1));
        
        return LIS(0, -1, nums);
    }
};
