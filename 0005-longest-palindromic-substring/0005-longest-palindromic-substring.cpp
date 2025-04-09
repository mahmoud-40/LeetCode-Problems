class Solution {
public:
    vector<vector<bool>> isPal;

    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        isPal.assign(n, vector<bool>(n, false));
        int maxLen = 1, start = 0;

        // All single characters are palindromes.
        for (int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }

        // Check for 2-character palindromes.
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                isPal[i][i + 1] = true;
                maxLen = 2;
                start = i;
            }
        }

        // Check for lengths > 2.
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPal[i + 1][j - 1]) {
                    isPal[i][j] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};