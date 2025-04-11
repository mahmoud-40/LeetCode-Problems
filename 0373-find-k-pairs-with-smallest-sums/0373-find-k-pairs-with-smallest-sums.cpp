class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        for(int i = 0; i < nums1.size(); i++){
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        vector<vector<int>> res;

        while(k--){
            auto [sum, i, j] = minHeap.top(); 
            minHeap.pop();
            
            res.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return res;
    }
};