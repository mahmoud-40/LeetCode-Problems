public class Solution {
    public int Trap(int[] height) {
        int left = 0, right = height.Length - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftMax = Math.Max(leftMax, height[left]);
                ans += Math.Max(0, leftMax - height[left]);
                left++;
            } else {
                rightMax = Math.Max(rightMax, height[right]);
                ans += Math.Max(0, rightMax - height[right]);
                right--;
            }
        }

        return ans;
    }
}
