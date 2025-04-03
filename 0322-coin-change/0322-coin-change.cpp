class Solution {
public:
    vector<long long> cache;

    long long MinCoinsRequried(int amount, vector<int>& coins)
    {
        if(amount < 0){
            return INT_MAX;
        }

        if(amount == 0){
            return 0;
        }

        if(cache[amount] != -1){
            return cache[amount];
        }

        long long ch = INT_MAX;

        for(auto coin : coins){
            ch = min(ch, MinCoinsRequried(amount - coin, coins) + 1);
        }

        return cache[amount] = ch;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        cache.resize(amount + 15, -1);
        
        int ans = MinCoinsRequried(amount, coins);
        
        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};