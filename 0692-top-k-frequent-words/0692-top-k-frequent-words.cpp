class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const auto& word : words) {
            freq[word]++;
        }
        
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        
        for (const auto& entry : freq) {
            pq.push(entry);
        }
        
        vector<string> result;
        for (int i = 0; i < k && !pq.empty(); ++i) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        
        return result;
    }
};