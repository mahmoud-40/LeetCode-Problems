class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> freq(26, 0);

        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        while (t--) {
            vector<long long> new_freq(26, 0);
            for (int i = 0; i < 26; i++) {
                if (freq[i]) {
                    if (i == 25) { // 'z'
                        new_freq[0] = (new_freq[0] + freq[i]) % MOD;
                        new_freq[1] = (new_freq[1] + freq[i]) % MOD;
                    } else {
                        new_freq[i + 1] = (new_freq[i + 1] + freq[i]) % MOD;
                    }
                }
            }
            freq = new_freq;
        }

        long long ans = 0;
        for (auto count : freq) {
            ans = (ans + count) % MOD;
        }

        return ans;
    }
};
