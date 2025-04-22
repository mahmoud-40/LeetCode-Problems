class Solution {
public:

    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
        if(i >= size(A)) return mustPick ? 0 : -1e5;
        if(dp[mustPick][i] != -1) return dp[mustPick][i];
        if(mustPick)
            return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
        return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        int mx = solve(nums, 0, false, dp);

        int sum = 0, mxSum = INT_MIN;

        vector<int> pref(nums.size() + 1, 0);
        vector<int> suff(nums.size() + 1, 0);

        pref[0] = nums[0];
        suff[nums.size() - 1] = nums[nums.size() - 1];

        int sumPref = nums[0], mxSumPref = nums[0];
        
        for(int i = 1; i < nums.size(); i++){ 
            sumPref += nums[i];
            mxSumPref = max(mxSumPref, sumPref);
            pref[i] = mxSumPref;
        }
        
        int sumSuff = nums[nums.size() - 1], mxSumSuff = nums[nums.size() - 1];

        for(int i = nums.size() - 2; i >= 0; i--){ 
            sumSuff += nums[i];
            mxSumSuff = max(mxSumSuff, sumSuff);
            suff[i] = mxSumSuff;
        }

        for(int i = 0; i < nums.size(); i++){ 
            mxSum = max({mx, pref[i] + suff[i + 1]}); 
        }

        return mxSum;
    }
};