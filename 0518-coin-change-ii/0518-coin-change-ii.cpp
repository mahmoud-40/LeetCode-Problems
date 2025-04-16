class Solution {
public:
    vector<vector<int>> memo;

    int countCombinations(int amount, vector<int>& coins, int index) {
        if (amount == 0) return 1;
        if (amount < 0 || index == coins.size()) return 0;
        if (memo[amount][index] != -1) return memo[amount][index];

        int include = countCombinations(amount - coins[index], coins, index);
        int exclude = countCombinations(amount, coins, index + 1);

        return memo[amount][index] = include + exclude;
    }

    int change(int amount, vector<int>& coins) {
        memo.resize(amount + 1, vector<int>(coins.size(), -1));
        return countCombinations(amount, coins, 0);
    }
};