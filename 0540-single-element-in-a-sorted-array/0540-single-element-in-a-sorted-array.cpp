class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int NonDuplicateNum = 0;

        for(int num : nums){
            NonDuplicateNum ^= num;
        }

        return NonDuplicateNum;
    }
};