class Solution {
public:
    bool checkUnique(int st, vector<int>& nums){
        unordered_set<int> seen;
        for (int i = st; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                return false;
            }
            seen.emplace(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 3) {
            if (checkUnique(i, nums)) {
                return ans;
            }

            ans++;
        }
        return ans;
    }
};