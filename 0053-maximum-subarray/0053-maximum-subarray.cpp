class Solution {
public:

    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, mxSum = INT_MIN;

        for(int i = 0; i< nums.size(); i++){ // -5 4 2
            sum += nums[i]; // -5, sum = 0 + 4 + 2

            mxSum = max(sum, mxSum); // -5 // 4 // 6

            if(sum < 0) // true false false
            {    
                sum = 0; 
            }
        }

        return mxSum; // 6
    }
};