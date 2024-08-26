class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s = "", t = "";
        for(auto c : word1){
            s += c;
        }
        for(auto c : word2){
            t += c;
        }
        if(s == t){
            return true;
        }else{
            return false;
        }
    }
};