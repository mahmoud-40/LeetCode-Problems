class Solution {
public:
    bool canConstruct(string s, int k) {
        int mp[26];

        for(auto ch : s){ 
            mp[ch - 'a']++;
        }

        int cnt = 0;

        for(auto ch : s){ 
            if(mp[ch - 'a'] % 2){ 
                cnt++;
                mp[ch - 'a'] = 0;
            }
        }

        if(cnt > k || k > s.size()){
            return false;
        }

        return true;
    }
};