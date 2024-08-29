class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> row, col;
        int n = stones.size();

        for (int i = 0; i < n; i++) {
            int x = stones[i][0];
            int y = stones[i][1];
            row[x].push_back(i);
            col[y].push_back(i);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cnt = 0; 
                dfs(i, stones, vis, row, col, cnt);
                ans += cnt - 1;
            }
        }

        return ans; 
    }

private:
    void dfs(int idx, vector<vector<int>>& stones, vector<bool>& vis,
             unordered_map<int, vector<int>>& row,
             unordered_map<int, vector<int>>& col,
             int& cnt) {
        vis[idx] = true;
        cnt++; 

        int x = stones[idx][0];
        int y = stones[idx][1];

        for (int i : row[x]) {
            if (!vis[i]) {
                dfs(i, stones, vis, row, col, cnt);
            }
        }

        for (int i : col[y]) {
            if (!vis[i]) {
                dfs(i, stones, vis, row, col, cnt);
            }
        }
    }
};
