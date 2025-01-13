class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);

        for(auto ch : s){
            freq[ch - 'a']++;
        }

        int ans = 0;
        
        for(int i = 0; i < freq.size() ; i++)
        {
            if(freq[i] >= 3){
                if(freq[i] % 2){
                    ans++;
                }
                else{
                    ans += 2;
                }
            }else{
                ans += freq[i];
            }
        }

        return ans;
    }
};