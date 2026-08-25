class Solution {
    public int missingMultiple(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        
        for (int num : nums) {
            set.add(num);
        }

        int target = k;
        while (set.contains(target)) {
            target += k;
        }

        return target;
    }
}