class Solution {
public:
    static const int MaxSize = 100 + 5;
    long long dp[MaxSize][MaxSize];  
    
    long long rec(int row, int col, vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // Out of bounds or obstacle → 0 paths
        if (row >= m || col >= n || obstacleGrid[row][col] == 1) {
            return 0;
        }

        // Reached the end → 1 path
        if (row == m - 1 && col == n - 1) {
            return 1;
        }

        if (dp[row][col] != -1) {
            return dp[row][col];
        }

        long long right = rec(row, col + 1, obstacleGrid);
        long long down = rec(row + 1, col, obstacleGrid);

        return dp[row][col] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));

        return rec(0, 0, obstacleGrid);
    }
};