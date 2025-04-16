class Solution {
public:
    int numTrees(int n) {
        vector<int> uniqTree(n + 1, -1); 
        return getBST(n, uniqTree);    
    }

    int getBST(int n, vector<int> &uniqTree){
        if(n == 0)
            return 1;

        if(n == 1)
            return 1;

        if (uniqTree[n] != -1) 
            return uniqTree[n];

        int left = 0, right = 0;
        int total = 0;

        for(int i = 1; i <= n; i++){
            left = getBST(i - 1, uniqTree);
            right = getBST(n - i, uniqTree);
            total += left * right;
        }

        return uniqTree[n] = total;
    }
};