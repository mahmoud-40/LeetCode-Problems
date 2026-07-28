class Solution {
public:
    string smallestPalindrome(string s) {
        sort(s.begin(), s.end());
        
        string ans = "";
        int n = s.size();

        for(int i = 0; i< n; i += 2){
            ans += s[i];
        }


        if(n % 2) n--;

        for(int i = n - 1; i > 0; i -= 2){
            ans += s[i];
        }

        return ans;
    }
};