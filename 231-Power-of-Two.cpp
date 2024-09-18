class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 2 ^ x == n ?
        return n > 0 && (n & (n - 1)) == 0;
    }
};