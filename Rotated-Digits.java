1class Solution {
2    public boolean isGood(int n){
3        boolean has_different = false;
4        String str = String.valueOf(n);
5        
6        for (int i = 0; i < str.length(); i++){
7            char c = str.charAt(i);
8            
9            if(c == '3' || c == '4' || c == '7'){
10                return false;
11            }
12            else if(c == '2' || c == '5' || c == '6' || c == '9'){
13                has_different = true;
14            }
15        }
16        return has_different;
17    } 
18
19    public int rotatedDigits(int n) {
20        int count = 0;
21        for(int i = 1; i <= n; i++){ 
22            if(isGood(i)){
23                count++;
24            }
25        }
26        return count;
27    }
28}