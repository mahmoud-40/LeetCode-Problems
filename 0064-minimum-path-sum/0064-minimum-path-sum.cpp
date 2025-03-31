class Solution {
public:
    static const int MaxSize = 200 + 5;
    int dp[MaxSize][MaxSize];

    int rec(int row, int col, vector<vector<int>>& grid)
    {
        if(row >= grid.size() || col >= grid[0].size()){
            return INT_MAX; 
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        if(row == grid.size()-1 && col == grid[0].size()-1){
            return dp[row][col] = grid[row][col];
        }

        int right = rec(row, col + 1, grid);
        int down = rec(row + 1, col, grid);

        return dp[row][col] = grid[row][col] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < MaxSize; i++){
            for(int j = 0; j < MaxSize; j++){
                dp[i][j] = -1;
            }
        }

        return rec(0, 0, grid);
    }
};