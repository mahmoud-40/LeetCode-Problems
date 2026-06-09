1class Solution {
2    public long maxTotalValue(int[] nums, int k) {
3        long mx = Long.MIN_VALUE;
4        long mn = Long.MAX_VALUE;
5
6        for(long num : nums){
7            mx = Math.max(mx, num);
8            mn = Math.min(mn, num);
9        }
10
11        return (mx - mn) * k;
12    }
13}