class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1; 
        k--; 

        while (k > 0) {
            int steps = cnt(curr, n);
            if (steps <= k) {
                curr++;
                k -= steps; 
            } else {
                curr *= 10; 
                k--; 
            }
        }
        return curr;
    }

private:
    int cnt(int curr, int n) {
        long long steps = 0;
        long long first = curr;
        long long last = curr + 1;

        while (first <= n) {
            steps += std::min(n + 1, (int)last) - first; // Count numbers in the range [first, last)
            first *= 10;
            last *= 10;
        }
        return steps;
    }
};
