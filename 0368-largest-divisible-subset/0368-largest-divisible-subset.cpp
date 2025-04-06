class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> parent;
    vector<int> nums;

    int rec(int i, int last, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i][last + 1] != -1) {
            return dp[i][last + 1];
        }

        int ch1 = rec(i + 1, last, nums); // exclude the current element
        int ch2 = 0; // include the current element

        if (last == -1 || nums[i] % nums[last] == 0) {
            ch2 = 1 + rec(i + 1, i, nums);
        }

        if (ch2 > ch1) {
            parent[i][last + 1] = i;
            dp[i][last + 1] = ch2;
        } else {
            parent[i][last + 1] = last;
            dp[i][last + 1] = ch1;
        }

        return dp[i][last + 1];
    }

    vector<int> getAns() {
        vector<int> ans;
        int curr = 0;
        int last = -1;

        while (curr < nums.size()) {
            if (parent[curr][last + 1] == curr) {
                ans.push_back(nums[curr]);
                last = curr;
            }
            curr++;
        }
        return ans;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) 
            return {};
        
        sort(nums.begin(), nums.end());

        this->nums = nums;
        int n = nums.size();
        
        dp.assign(n, vector<int>(n + 1, -1));
        parent.assign(n, vector<int>(n + 1, -1));

        rec(0, -1, nums);
        return getAns();
    }
};
