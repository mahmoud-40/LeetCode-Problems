class Solution {
public:

    bool wordBreak(const string& s, const vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        int size = s.length();
        vector<bool> Cache(size + 1, false);
        Cache[0] = true; 

        for (int i = 1; i <= size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (Cache[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    Cache[i] = true;
                    break; 
                }
            }
        }

        return Cache[size]; 
    }

};