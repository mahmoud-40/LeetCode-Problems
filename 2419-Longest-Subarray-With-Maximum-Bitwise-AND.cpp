class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()); 
        int cnt = 0, ans = 0;

        for (int num : nums) {
            if (num == mx) { 
                cnt++; 
            } else {
                ans = max(ans, cnt); 
                cnt = 0; 
            }
        }
        
        ans = max(ans, cnt); 
        return ans;
    }
};