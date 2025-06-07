class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        if (n == 0) return "";
        vector<bool> removed(n, false);
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;
        
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], -i});
            } else {
                if (!pq.empty()) {
                    auto [c, neg_idx] = pq.top();
                    pq.pop();
                    int idx = -neg_idx;
                    removed[idx] = true;
                }
            }
        }
        
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !removed[i]) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};