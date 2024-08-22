class Solution {
public:
    string filter(const string& s) {
        string t;
        for (char c : s) {
            if (isalpha(c) ||  isdigit(c)) {
                t += tolower(c);
            }
        }
        return t;
    }
    bool isPalindrome(string s) {
        s = filter(s);
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
};