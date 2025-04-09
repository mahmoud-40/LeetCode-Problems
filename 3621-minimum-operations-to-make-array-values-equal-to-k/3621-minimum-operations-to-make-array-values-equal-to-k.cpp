class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;

        map<int, int> freq;

        for(auto num : nums){
            freq[num]++;
        }

        for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
           int num = it->first;
            if(num > k){
                ans++;
            }
            else if(num < k){
                return -1;
            }
        }

        return ans;
    }
};