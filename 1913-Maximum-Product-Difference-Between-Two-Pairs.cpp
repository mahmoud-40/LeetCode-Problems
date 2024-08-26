class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0], b = nums[1];
        int c = nums[nums.size() - 1], d = nums[nums.size() - 2];
        int mxProduct = (c * d) - (a * b);
        return mxProduct;
    }
};