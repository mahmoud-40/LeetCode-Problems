class Solution {
public:
    vector<int> computeLPS(const string& s) {
        int n = s.length();
        vector<int> lps(n, 0);
        int length = 0; 
        int i = 1;

        while (i < n) {
            if (s[i] == s[length]) {
                length++;
                lps[i] = length;
                i++;
            } else {
                if (length != 0) {
                    length = lps[length - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    string shortestPalindrome(string s) {
        if (s.empty()) return \\;

        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + \#\ + rev;  

        vector<int> lps = computeLPS(combined);
        int palLen = lps.back(); 
        
        string toAdd = rev.substr(0, rev.length() - palLen);

        return toAdd + s; 
    }
};