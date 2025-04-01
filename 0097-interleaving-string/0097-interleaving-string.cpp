class Solution {
public:
    int dp[101][101];
    
    bool rec(int i, int j, int k, string &s1, string &s2, string &s3) {
        if (i == s1.length() && j == s2.length() && k == s3.length()) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool res = false;

        if (i < s1.length() && s1[i] == s3[k]) {
            res |= rec(i + 1, j, k + 1, s1, s2, s3);
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            res |= rec(i, j + 1, k + 1, s1, s2, s3);
        }

        return dp[i][j] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0, s1, s2, s3);
    }
};