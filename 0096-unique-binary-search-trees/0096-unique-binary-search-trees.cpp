class Solution {
public:
    int numTrees(int n) {
        vector<int> memo(n + 1, -1); 
        return getBST(n, memo);    
    }

    int getBST(int n, vector<int> &memo){
        if(n == 0)
            return 1;
            
        if(n == 1)
            return 1;

        if (memo[n] != -1) 
            return memo[n];

        int left = 0, right = 0;
        int total = 0;

        for(int i = 1; i <= n; i++){
            left = getBST(i - 1, memo);
            right = getBST(n - i, memo);
            total += left * right;
        }

        return memo[n] = total;
    }
};