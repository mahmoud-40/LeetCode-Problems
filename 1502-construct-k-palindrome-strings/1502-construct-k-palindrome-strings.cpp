class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char, int> mp;
        // set<char> st;

        for(auto ch : s){
            mp[ch]++;
            // st.insert(ch);
        }

        int cnt = 0;

        for(auto ch : s){
            if((mp[ch] % 2 != 0)){
                cnt++;
                mp[ch] = 0;
            }

            if(cnt > k){
                return false;
            }
        }

        if(cnt > k || k > s.size()){
            return false;
        }

        return true;
    }
};