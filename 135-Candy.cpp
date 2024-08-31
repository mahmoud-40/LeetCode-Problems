#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        if (n == 0)
            return 0;

        vector<int> memo(n, -1);

        for (int i = 0; i < n; ++i)
        {
            dp(ratings, memo, i);
        }

        int sum = 0;
        for (int i : memo)
        {
            sum += i;
        }

        return sum;
    }

private:
    int dp(const vector<int> &ratings, vector<int> &memo, int idx)
    {
        if (memo[idx] != -1)
        {
            return memo[idx];
        }

        int n = ratings.size();
        int ans = 1;

        if (idx > 0 && ratings[idx] > ratings[idx - 1])
        {
            ans = max(ans, dp(ratings, memo, idx - 1) + 1);
        }

        if (idx < n - 1 && ratings[idx] > ratings[idx + 1])
        {
            ans = max(ans, dp(ratings, memo, idx + 1) + 1);
        }

        memo[idx] = ans;
        return ans;
    }
};
