class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid) {
        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0'; // Mark as visited

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Explore all four directions
            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check boundaries and if the cell is land
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == '1') {
                    grid[newX][newY] = '0'; // Mark as visited
                    q.push({newX, newY}); // Add to the queue
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int lands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                // If we find a '1', it's the start of a new island
                if (grid[i][j] == '1') {
                    lands++;
                    bfs(i, j, grid); // perform BFS to mark the entire island
                }
            }
        }
        return lands;
    }
};
