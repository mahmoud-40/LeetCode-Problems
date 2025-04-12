class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        set<int> st;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
            st.insert(nums[i]);
        }

        int cnt = 0, ans = 0;

        for(int i = 0 ; i < nums.size() ; i++){ 
            int x = nums[i];    
            if(!mp[x - 1]){  
               while(mp[x]){ 
                x++;  
                cnt++;  
               } 
            }

            ans = max(ans, cnt);  

            cnt = 0;

            if(ans >= st.size())
                return st.size();
        }

        return ans;
    }
};