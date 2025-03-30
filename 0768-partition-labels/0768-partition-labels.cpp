class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> last;
        for(int i = 0; i < s.size(); i++){
            last[s[i]] = i;
        }

        vector<int> ans;
        int l = 0, r = last[s[l]];

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            r = max(r, last[ch]);

            if(i == r){
                ans.push_back(r - l + 1);
                l = r + 1;
                r = last[s[l]];
            }
        }
        return ans;
    }
};