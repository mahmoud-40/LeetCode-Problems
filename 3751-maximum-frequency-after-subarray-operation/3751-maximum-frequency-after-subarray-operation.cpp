class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        vector<int> freq(51, 0);
        int ans = 0;
        int cntK = 0, mxFreq = 0;
        for(auto i : nums){
            freq[i] = max(cntK, freq[i]) + 1;
            if(i == k){
                cntK++;
                ans++;
            }
            ans = max(ans, freq[i]);
        }
        
        return ans;
    }
};