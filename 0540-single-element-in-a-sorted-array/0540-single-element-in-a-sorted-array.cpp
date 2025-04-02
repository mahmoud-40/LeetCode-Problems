class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r){
            int mid = (l + r) / 2;

            if(mid % 2){
                mid--;
            }

            if(nums[mid] == nums[mid + 1]){
                l = mid + 2;
            }
            else{
                r = mid;
            }
        }

        return nums[l];
    }
};

/*
Complexity:

- Time complexity: O(n)
- Space complexity: *O*(1)

---------------------

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
*/