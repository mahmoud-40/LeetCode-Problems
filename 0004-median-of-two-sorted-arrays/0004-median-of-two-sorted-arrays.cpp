class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        if (n > m) {
            swap(a, b);
            swap(n, m);
        }

        int l = 0, r = n;
        while (l <= r) {
            int p1 = (l + r) / 2;
            int p2 = (n + m + 1) / 2 - p1;

            int maxL1 = (p1 == 0) ? INT_MIN : a[p1 - 1];
            int minR1 = (p1 == n) ? INT_MAX : a[p1];

            int maxL2 = (p2 == 0) ? INT_MIN : b[p2 - 1];
            int minR2 = (p2 == m) ? INT_MAX : b[p2];

            if (maxL1 <= minR2 && maxL2 <= minR1) {
                if ((n + m) % 2 == 0) {
                    return (max(maxL1, maxL2) + min(minR1, minR2)) / 2.0;
                } else {
                    return max(maxL1, maxL2);
                }
            } else if (maxL1 > minR2) {
                r = p1 - 1;
            } else {
                l = p1 + 1;
            }
        }

        return 0;
    }
};