class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        set<int> v;
        for (auto s : timePoints) {
            int x = stoi(s.substr(0, 2)); 
            int y = stoi(s.substr(3, 2)); 

            int z = x * 60 + y;
            v.insert(z);
        }

        if (v.size() < timePoints.size()) {
            return 0;
        }

        vector<int> times(v.begin(), v.end());
        int mn = INT_MAX;

        for (int i = 0; i < times.size(); i++) {
            int diff = (times[(i + 1) % times.size()] - times[i] + 1440) % 1440; 
            mn = min(mn, diff);
        }

        return mn;
    }
};
