class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int mx = 0;
        int temp = 0;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < mn) {
                mn = prices[i];
            }
            
            temp = prices[i] - mn;
            if (temp > mx) {
                mx = temp;
            }
        }

        return mx;
    }
};