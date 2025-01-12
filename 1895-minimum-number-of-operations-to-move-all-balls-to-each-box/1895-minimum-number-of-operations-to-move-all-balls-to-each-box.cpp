#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> idx;
        ordered_set st;

        // Collect indices of '1' and insert into the ordered set
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                idx.push_back(i);
                st.insert(i);
            }
        }

        // Compute prefix sums of indices
        vector<int> pref(idx.size(), 0);
        if (!idx.empty()) pref[0] = idx[0];
        for (int i = 1; i < idx.size(); i++) {
            pref[i] = pref[i - 1] + idx[i];
        }

        vector<int> ans;
        int n = idx.size(), m = boxes.size();

        for (int i = 0; i < m; i++) {
            int before = st.order_of_key(i);
            int after = st.size() - before;

            int sumL = 0, sumR = 0;

            // Calculate sum of distances to the left
            if (before > 0) {
                sumL = before * i - (before > 0 ? pref[before - 1] : 0);
            }

            // Calculate sum of distances to the right
            if (after > 0) {
                sumR = (pref[n - 1] - (before > 0 ? pref[before - 1] : 0)) - after * i;
            }

            ans.push_back(sumL + sumR);
        }

        return ans;
    }
};
