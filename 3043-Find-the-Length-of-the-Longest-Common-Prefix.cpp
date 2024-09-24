class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> pref;

        for (int i : arr1) {
            string s = to_string(i);
            for (size_t len = 1; len <= s.length(); ++len) {
                pref.insert(s.substr(0, len));
            }
        }

        int ans = 0;

        for (int i : arr2) {
            string s = to_string(i);
            for (size_t len = 1; len <= s.length(); ++len) {
                string p = s.substr(0, len);
                if (pref.find(p) != pref.end()) {
                    ans = max(ans, (int)p.length());
                } else {
                    break; 
                }
            }
        }

        return ans;
    }
};