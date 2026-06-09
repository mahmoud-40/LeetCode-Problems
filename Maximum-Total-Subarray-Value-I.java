1class Solution {
2    public long maxTotalValue(int[] nums, int k) {
3        long mx = Arrays.stream(nums).max().getAsInt();
4        long mn = Arrays.stream(nums).min().getAsInt();
5
6        return (mx - mn) * k;
7    }
8}