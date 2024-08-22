class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p = 0;
        map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            freq[x]++; 
            
            if (freq[x] <= 2) {
                nums[p++] = x; 
            }
        }
        return p;
    }
};
