class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool special = true;
        bool odd = true;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2){
                if(odd && i){
                    special = false;
                    break;
                }
                odd = true;
            }
            else{
                if(!odd && i){
                    special = false;
                    break;
                }
                odd = false;
            }
        }

        return special;
    }
};