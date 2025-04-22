class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int start = 0;
        int sumA = 0,sumB = 0;
        for(int i=0;i<gas.size();i++){
            totalGas += (gas[i] - cost[i]);
            sumA+=gas[i], sumB += cost[i];
            if(totalGas<0) {
                totalGas = 0;
                start = i+1;
            }
        }
        if(sumA < sumB){
            return -1;
        } else {
            return start;
        }
    }
};