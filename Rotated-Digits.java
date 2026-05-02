1class Solution {
2    String s;
3    int[][] memo; 
4
5    int dp(int pos, boolean tight, boolean hasChanged){
6        if(pos == s.length()) return hasChanged ? 1 : 0;
7
8        if(!tight && memo[pos][hasChanged ? 1 : 0] != -1)
9            return memo[pos][hasChanged ? 1 : 0];
10
11        int limit = tight ? (s.charAt(pos) - '0') : 9;
12        int count = 0;
13
14        for(int d = 0; d <= limit; d++){
15            if(d == 3 || d == 4 || d == 7) continue;
16            boolean newTight = tight && (d == limit);
17            boolean newChanged = hasChanged || (d==2||d==5||d==6||d==9);
18            count += dp(pos + 1, newTight, newChanged);
19        }
20
21        if(!tight)
22            memo[pos][hasChanged ? 1 : 0] = count;
23
24        return count;
25    }
26
27    public int rotatedDigits(int n) {
28        s = String.valueOf(n);
29        memo = new int[s.length()][2];
30        for(int[] row : memo) Arrays.fill(row, -1);
31        return dp(0, true, false);
32    }
33}