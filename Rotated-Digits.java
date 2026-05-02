1class Solution {
2    String s;
3
4    int dp(int[][][] memo, int pos, boolean tight, boolean hasChanged){
5        if(pos == s.length()){
6            return hasChanged ? 1 : 0;
7        }
8
9        if(memo[pos][tight ? 1 : 0][hasChanged ? 1 : 0] != -1){
10            return memo[pos][tight ? 1 : 0][hasChanged ? 1 : 0];
11        }
12
13        int limit = tight ? (s.charAt(pos) - '0') : 9;
14        int count = 0;
15
16        for (int d = 0; d <= limit; d++){
17            if(d == 3 || d == 4 || d == 7) continue;
18
19            boolean newTight = tight && (d == limit);
20            boolean newChanged = hasChanged || (d == 2 || d == 5 || d == 6 || d == 9);
21
22            count += dp(memo, pos + 1, newTight, newChanged);
23        }
24
25        return memo[pos][tight ? 1 : 0][hasChanged ? 1 : 0] = count;
26    }
27
28    public int rotatedDigits(int n) {
29        s = String.valueOf(n);
30        int[][][] memo = new int[s.length()][2][2];
31
32        for(int[][] a : memo)
33            for(int[] b : a)
34                Arrays.fill(b, -1);
35
36        return dp(memo, 0, true, false);
37    }
38}