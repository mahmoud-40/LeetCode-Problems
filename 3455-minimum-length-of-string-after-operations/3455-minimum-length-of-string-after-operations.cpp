class Solution {
public:
    int minimumLength(string s) {
        // freq : s
        // freq[ch] > 3 -> multiply 3 -> (freq[ch] % 3)
        // freq[ch] < 3 -> freq[ch] 
        // ans : acbcb -> 5
        // s: aa -> ans = s = aa -> 2
        // s: abaacbcbb
        // st : a b c
        // a -> 3 -> 1
        // b -> 4 -> 2
        // c -> 2 -> 2

        map<char, int> freq;
        set<char> st;

        for(auto ch : s){
            freq[ch]++;
            st.insert(ch);
        }

        int ans = 0;


        // a -> 9 -> 9 7 5 3 1 
        // a -> 12-> 10 8 6 4 2 
        // a -> 15-> 15 13 11 9 7 5 3 1 
        // a -> 17-> 17 15 
        // a -> 18-> 18 16 14 12 10 8 6 4 2

        // odd -> 1
        // even-> 2  

        // b -> 8
        // c -> 7
        // 

        for(auto ch : st){
            if(freq[ch] >= 3){
                if(freq[ch] % 2){
                    ans++;
                }
                else{
                    ans += 2;
                }
            }else{
                ans += freq[ch];
            }
        }

        return ans;
    }
};