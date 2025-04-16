class Solution {
public:
    int minPartitions(string n) {
        int mxNum = 0;

        for(auto digit : n){
            int num = digit - '0';
            mxNum = max(num, mxNum);
        }

        return mxNum;
    } 
};