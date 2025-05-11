class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        // 2 6 4 1
        int cnt = 0;

        for(int n : arr){
            if(n % 2){
                cnt++;
            }
            else{
                cnt = 0;
            }

            if(cnt >= 3){
                return true;
            }
        }
        return false;
    }
};