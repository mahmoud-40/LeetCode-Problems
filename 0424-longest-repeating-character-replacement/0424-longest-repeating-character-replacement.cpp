class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq;

        int l = 0;
        int mxFreq = 0, res = 0;

        for(int r = 0; r < s.size(); r++){
            freq[s[r]]++;
            mxFreq = max(mxFreq, freq[s[r]]);

            while((r - l + 1) - mxFreq > k){
                freq[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};