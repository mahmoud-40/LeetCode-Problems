class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int mx = 0;
        map<char, int> freq;

        for(int i = 0; i < s.size(); i++){
            while(freq[s[i]]){
                freq[s[l]] = 0;
                l++;
            }

            freq[s[i]] = 1;
            mx = max(mx, i - l + 1);
        }

        return mx;
    }
};