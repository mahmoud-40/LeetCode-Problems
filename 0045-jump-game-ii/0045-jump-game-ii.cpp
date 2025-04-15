class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        int jumps = 0;        
        int currEnd = 0;       
        int farthest = 0;      
        
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);  
            
            if (i == currEnd) {   
                jumps++;
                currEnd = farthest;   
                
                if (currEnd >= nums.size() - 1) {
                    break;  
                }
            }
        }
        
        return jumps;
    }
};