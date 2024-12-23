class Solution {
public:
    vector<int> dp;
    int fun(vector<int>& coins, int k){
        if(k == 0)
            return 0;
        if(k < 0)
            return 1e9;

        if(dp[k] != -1){
            return dp[k];
        }

        int mn = 1e9;

        for(auto c : coins){
            int ch = fun(coins, k - c);

            if(ch != 1e9)
                mn = min(mn, ch + 1);
        }

        return dp[k] = mn; 
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 15, -1);

        sort(coins.begin(), coins.end());
        
        int ans = fun(coins, amount);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};