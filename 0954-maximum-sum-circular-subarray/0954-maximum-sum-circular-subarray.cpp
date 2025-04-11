class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0, mxSum = INT_MIN;

        // start ... end
        // 3 ....... 2
        // 0 ....... size
        // 1 ....... 0
        // sum = 0 -> st = i + 1 ... ed = i
        // 1 2 3 4 5
        //   ed st
        // (7 % 5)
        // 1 -2 3 -2
        // 1  1 2  2
        // 1 1 1 -2

        // max(mxSum, pref[i] + suff[i + 1])

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
            sum += nums[i]; 

            mxSum = max({sum, mxSum, pref[i] + suff[i + 1]}); 

            if(sum < 0) 
            {    
                sum = 0; 
            }
        }

        return mxSum;
    }
};