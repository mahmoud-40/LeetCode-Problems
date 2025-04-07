class Solution {
public:
    vector<vector<int>> cache;

    int formSum(int idx, int sum, int total, vector<int>& nums)
    {
        if(idx >= nums.size()){
            return 0;
        }

        if(sum > (total / 2))
            return 0;

        if(sum == (total / 2)){
            return 1;
        }
        
        if(cache[idx][sum] != -1){
            return cache[idx][sum];
        }

        int take = formSum(idx + 1, sum + nums[idx], total, nums);
        int skip = formSum(idx + 1, sum, total, nums);

        if(take == 1 || skip == 1){
            return cache[idx][sum] = 1;
        }

        return cache[idx][sum] = 0;
    }

    bool canPartition(vector<int>& nums) {

        int total = 0;

        for(auto num : nums){
            total += num;
        }

        if(total % 2)
            return false;

        cache.assign(nums.size(), vector<int>((total / 2) + 1, -1));

        int can = formSum(0, 0, total, nums);

        if(can == 1){
            return true;
        }    

        return false;
    }
};