class Solution {
    public boolean isPalindrome(int x) {
        String num = String.valueOf(x);

        int n = num.length();

        for(int i = 0; i < n; i++){
            if(num.charAt(i) != num.charAt(n - i - 1))
             return false;
        }

        return true;
    }
}