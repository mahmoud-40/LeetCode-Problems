class Solution {
private:
    unordered_map<int, int> memo;
    unordered_set<string> dict; 

    int dp(const string& s, int idx) {
        if (idx >= s.size()) 
            return 0; 

        if (memo.count(idx)) 
            return memo[idx]; 

        int mn = 1 + dp(s, idx + 1);

        for (int end = idx + 1; end <= s.size(); ++end) {
            string sub = s.substr(idx, end - idx);

            if (dict.count(sub)) {
                mn = min(mn, dp(s, end));
            }
        }

        memo[idx] = mn; 

        return mn;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        dict = unordered_set<string>(dictionary.begin(), dictionary.end());

        return dp(s, 0);
    }
};