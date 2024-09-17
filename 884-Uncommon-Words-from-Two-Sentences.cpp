class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> t1, t2;
        map<string, int> mp;

        // Split s1 into words
        istringstream stream1(s1);
        string word;
        while (stream1 >> word) {
            mp[word]++;
        }

        // Split s2 into words
        istringstream stream2(s2);
        while (stream2 >> word) {
            mp[word]++;
        }

        vector<string> ans;
        for (const auto& entry : mp) {
            if (entry.second == 1) {
                ans.push_back(entry.first);
            }
        }

        return ans;
    }
};