class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int size = (n + m); // size is odd -> mid
                            // size is even -> (mid1 + mid2) / 2
        
        if (n > m) {
           nums1.insert(nums1.end(), nums2.begin(), nums2.end());
           sort(nums1.begin(), nums1.end());
            if(size % 2){
                return (double)nums1[size/2];
            }
            else{
                int mid1 = nums1[size/2 - 1], mid2 = nums1[size/2];
                return (double)(mid1 + mid2) / 2;
            }
        } else {
            nums2.insert(nums2.end(), nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            if(size % 2){ // 3   [2]
                int idx = size / 2;
                return (double)nums2[size/2];
            }
            else{
                int mid1 = nums2[size/2 - 1], mid2 = nums2[size/2];
                return (double)(mid1 + mid2) / 2;
            }
        }
        return 0.0;
    }
};