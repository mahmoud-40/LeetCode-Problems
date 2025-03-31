class Solution {
public:
    static const int MaxSize = 100 + 5;
    int dp[MaxSize][MaxSize];

    int rec(int row, int col, vector<vector<int>>& obstacleGrid)
    {
        if(row >= obstacleGrid.size() || col >= obstacleGrid[0].size() || obstacleGrid[row][col]){
            return 0; 
        }

        if(row == obstacleGrid.size()-1 && col == obstacleGrid[0].size()-1){
            return 1;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int right = rec(row, col + 1, obstacleGrid);
        int down = rec(row + 1, col, obstacleGrid);

        return dp[row][col] = right + down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i = 0; i < MaxSize; i++){
            for(int j = 0; j < MaxSize; j++){
                dp[i][j] = -1;
            }
        }

        return rec(0,0, obstacleGrid);
    }
};