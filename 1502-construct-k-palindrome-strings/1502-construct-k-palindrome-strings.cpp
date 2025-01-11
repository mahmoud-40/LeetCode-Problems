class Solution {
public:
    bool canConstruct(string s, int k) {
        int mp[26];

        for(auto ch : s){ 
            mp[ch - 'a']++;
        }

        int cnt = 0;

        for(auto i = 0; i < 26 ; i++){ 
            if(mp[i] % 2){ 
                cnt++;
            }
        }

        if(cnt > k || k > s.size()){
            return false;
        }

        return true;
    }
};