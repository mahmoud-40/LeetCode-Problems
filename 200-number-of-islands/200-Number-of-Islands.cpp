class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i >= grid.size() or j >= grid[0].size() or i < 0 or j < 0 or grid[i][j] == '0'){
            return;
        } 

        grid[i][j] = '0';

        dfs(i - 1, j, grid); 
        dfs(i, j - 1, grid); 
        dfs(i, j + 1, grid); 
        dfs(i + 1, j, grid); 
    }
};