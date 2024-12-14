#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        int l = 0;
        deque<int> maxDeque, minDeque; 

        for (int r = 0; r < n; ++r) {

            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[r]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(r);

            while (!minDeque.empty() && nums[minDeque.back()] >= nums[r]) {
                minDeque.pop_back();
            }
            minDeque.push_back(r);

            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (maxDeque.front() == l) maxDeque.pop_front();
                if (minDeque.front() == l) minDeque.pop_front();
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};
