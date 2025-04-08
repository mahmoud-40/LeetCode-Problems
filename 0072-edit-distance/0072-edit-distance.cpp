class Solution {
public:
    int minDistanceHelper(string& word1, string& word2, int i, int j, vector<vector<int>>& memo) {
        if (i == word1.length()) {
            // Insert all remaining characters of word2
            return word2.length() - j;
        }
        if (j == word2.length()) {
            // Delete all remaining characters of word1
            return word1.length() - i;
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        if (word1[i] == word2[j]) {
            memo[i][j] = minDistanceHelper(word1, word2, i + 1, j + 1, memo);
            return memo[i][j];
        }
        
        int insertOp = minDistanceHelper(word1, word2, i, j + 1, memo);
        int deleteOp = minDistanceHelper(word1, word2, i + 1, j, memo);
        int replaceOp = minDistanceHelper(word1, word2, i + 1, j + 1, memo);
        
        return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.length(), vector<int>(word2.length(), -1));
        return minDistanceHelper(word1, word2, 0, 0, memo);
    }
};