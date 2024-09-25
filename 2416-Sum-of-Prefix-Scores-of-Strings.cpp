class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& nums) {
        ios::sync_with_stdio(0); 
        cin.tie(0);              
        cout.tie(0);
        
        int n = nums.size();
        unordered_map<long long, int> mp;
        long long mod = 1e15 + 7;

        for (const string& word : nums) {
            long long hash = 0;
            for (char c : word) {
                hash = (hash * 31 + c) % mod;
                mp[hash]++;
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            long long hash = 0;
            int count = 0;
            for (char c : nums[i]) {
                hash = (hash * 31 + c) % mod;
                count += mp[hash];
            }
            ans[i] = count;
        }

        return ans;
    }
};