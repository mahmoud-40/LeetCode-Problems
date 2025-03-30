class Solution {
public:
    vector<vector<int>> dp; 
    
    Solution() : dp(205, vector<int>(205, -1)) {} 
    
    int rec(int i, int j, int n, vector<vector<int>>& triangle)
    {
        if(i == n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ch1 = rec(i + 1, j, n, triangle);
        int ch2 = rec(i + 1, j + 1, n, triangle);

        return dp[i][j] = triangle[i][j] + min(ch1, ch2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        return rec(0, 0, triangle.size(), triangle);
    }
};