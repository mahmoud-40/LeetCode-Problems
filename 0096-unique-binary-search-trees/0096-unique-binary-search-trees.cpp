class Solution {
public:
    unordered_map<int, int> memo;

    int numTrees(int n) {
        return getBST(n);    
    }

    int getBST(int n){
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;

        if(memo.count(n))
            return memo[n];

        int left = 0, right = 0;
        int total = 0;

        for(int i = 1; i <= n; i++){
            left = getBST(i - 1);
            right = getBST(n - i);
            total += left * right;
        }

        return memo[n] = total;
    }
};