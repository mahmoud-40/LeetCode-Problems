class Solution {
public:
    vector<vector<int>> dp;

    int countCombinations(int amount, int idx, vector<int>& coins) {
        if(amount == 0)
            return 1;
        if(idx == coins.size() || amount < 0)
            return 0;

        if(dp[amount][idx] != -1)
            return dp[amount][idx];

        int inc = countCombinations(amount - coins[idx], idx, coins);
        int exc = countCombinations(amount, idx + 1, coins);

        return dp[amount][idx] = inc + exc;
    }

    int change(int amount, vector<int>& coins) {
        dp.resize(amount + 1, vector<int>(coins.size(), -1));
        return countCombinations(amount, 0, coins);
    }
};