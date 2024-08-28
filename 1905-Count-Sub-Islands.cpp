class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int cnt = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    if (floodfill(i, j, grid1, grid2, m, n)) {
                        cnt++; 
                    }
                }
            }
        }
        return cnt;
    }

private:
    bool floodfill(int x, int y, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid2[x][y] == 0) {
            return true; 
        }

        bool isSub = grid1[x][y] == 1;

        grid2[x][y] = 0;

        if (!floodfill(x + 1, y, grid1, grid2, m, n)) {
            isSub = false; 
        }
        if (!floodfill(x - 1, y, grid1, grid2, m, n)) {
            isSub = false;
        }
        if (!floodfill(x, y + 1, grid1, grid2, m, n)) {
            isSub = false;
        }
        if (!floodfill(x, y - 1, grid1, grid2, m, n)) {
            isSub = false;
        }

        return isSub; 
    }
};