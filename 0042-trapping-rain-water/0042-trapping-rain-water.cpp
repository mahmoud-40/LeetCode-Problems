class Solution {
public:
    int trap(vector<int>& height) {
        int rightMax = 0, leftMax = 0;
        int l = 0, r = height.size() - 1;

        int ans = 0;

        while(l < r){
            if(height[r] > height[l]){
                leftMax = max(leftMax, height[l]);
                ans += max(0, leftMax - height[l]);
                l++;
            }else{
                rightMax = max(rightMax, height[r]);
                ans += max(0, rightMax - height[r]);
                r--;
            }
        }
        return ans;
    }
};
