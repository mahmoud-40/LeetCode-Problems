class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> maxHeap;
        for(int num : nums){
            maxHeap.push(num);
        }

        k--;
        
        while(k > 0){
            maxHeap.pop();
            k--;
        }

        return maxHeap.top();
    }
};