class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> index_map;
        index_map[0] = -1; 
        int max_length = 0;
        int state = 0; 

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == 'a') state ^= 1 << 0; 
            else if (c == 'e') state ^= 1 << 1; 
            else if (c == 'i') state ^= 1 << 2; 
            else if (c == 'o') state ^= 1 << 3;
            else if (c == 'u') state ^= 1 << 4; 
            
            if (index_map.find(state) != index_map.end()) {
                max_length = max(max_length, i - index_map[state]);
            } else {
                index_map[state] = i; 
            }
        }

        return max_length;
    }
};
