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
            int x = nums[i]; // 100 4 200 1  
            if(!mp[x - 1]){ // t 
               while(mp[x]){ // 1 2 3
                x++; // 4
                cnt++; // 4
               } 
            }

            ans = max(ans, cnt); // 4

            cnt = 0;

            if(ans >= st.size())
                return st.size();
        }

        return ans;
    }
};