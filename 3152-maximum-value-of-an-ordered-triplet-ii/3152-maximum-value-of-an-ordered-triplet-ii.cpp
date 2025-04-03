class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref_mx(n + 1), suff_mx(n + 1);

        pref_mx[0] = nums[0];

        for(int i = 1; i < n; i++){
            pref_mx[i] = max(nums[i], pref_mx[i - 1]);
        }

        suff_mx[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--){
            suff_mx[i] = max(nums[i], suff_mx[i + 1]);
        }

        long long ans = 0;

        for(int i = 1; i < n - 1; i++){
            long long diff = pref_mx[i - 1] - nums[i];
            ans = max(ans, diff * suff_mx[i + 1]);
        }
    
        if(ans < 0)
            return 0;
        else
            return ans;
    }
};