class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<bool> ans;

        vector<int> ones(n, 0);

        bool p = 1, last = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                ones[i]++;
                if (nums[i] % 2 == 0)
                {
                    p = 0;
                }
                else
                {
                    p = 1;
                }
            }
            else if (nums[i] % 2 == 0 && p)
            {
                ones[i]++;
                p = 0;
            }
            else if (nums[i] % 2 != 0 && !p)
            {
                ones[i]++;
                p = 1;
            }
        }

        vector<int> pref(n);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                pref[i] = ones[i];
            else
                pref[i] += pref[i - 1] + ones[i];
        }

        for (auto i : queries)
        {
            int l = i[0], r = i[1];

            if (l == 0)
            {
                if (pref[r] == (r - l + 1))
                {
                    ans.push_back(1);
                }
                else
                {
                    ans.push_back(0);
                }
            }
            else
            {
                int x = pref[r] - pref[l - 1];
                if (ones[l] == 0)
                {
                    x++;
                }
                if (x == (r - l + 1))
                {
                    ans.push_back(1);
                }
                else
                {
                    ans.push_back(0);
                }
            }
        }

        return ans;
    }
};

// 3 4 1 2 6
// 1 1 1 1 0

// 4 3 1 6
// 1 1 0 1