class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxJump = nums[0];

        for(int i = 0; i < nums.size(); i++){
            if(i)
                mxJump--;
            if(i == nums.size() - 1){
                return true;
            }
            if(mxJump == 0 && nums[i] == 0)
                return false;
            mxJump = max(mxJump, nums[i]);
        }

        return false;
    }
};