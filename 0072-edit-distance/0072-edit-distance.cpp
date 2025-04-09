class Solution {
public:
    vector<vector<int>> memo;

    int minDistanceHelper(string& word1, string& word2, int i, int j) {
        if(i == word1.size()){
            return word2.size() - j;
        }

        if(j == word2.size()){
            return word1.size() - i;
        }

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        if(word1[i] == word2[j]){
            return memo[i][j] = minDistanceHelper(word1, word2, i + 1, j + 1);
        }

        int insertOp = minDistanceHelper(word1, word2, i, j + 1);
        int deleteOp = minDistanceHelper(word1, word2, i + 1, j);
        int replaceOp = minDistanceHelper(word1, word2, i + 1, j + 1);

        return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

    int minDistance(string word1, string word2) {
        memo.assign(word1.length(), vector<int>(word2.length(), -1));

        return minDistanceHelper(word1, word2, 0, 0);
    }
};