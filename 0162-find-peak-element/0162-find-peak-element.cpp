class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int mxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        return mxIdx;
    }
};
