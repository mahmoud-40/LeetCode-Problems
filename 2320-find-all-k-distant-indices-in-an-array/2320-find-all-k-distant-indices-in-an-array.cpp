class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> idxs;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == key) {
                idxs.push_back(i);
            }
        }

        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            for(int idx : idxs) {
                if(abs(i - idx) <= k) {
                    ans.push_back(i);
                    break;  
                }
            }
        }

        return ans;
    }
};