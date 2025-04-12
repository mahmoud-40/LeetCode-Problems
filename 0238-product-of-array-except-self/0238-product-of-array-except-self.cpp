class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        vector<int> ans;

        int zeros = 0;

        for(auto num : nums)
        {
            if(num == 0)
                zeros++;
            else
                prod *= num;
        }

        for(auto num : nums){
            if(num == 0)
            {
                if(zeros - 1 > 0)
                    ans.push_back(0);
                else
                    ans.push_back(prod);
            }
            else{
                if(zeros)
                    ans.push_back(0);
                else
                    ans.push_back(prod / num);
            }
        }

        return ans;
    }
};