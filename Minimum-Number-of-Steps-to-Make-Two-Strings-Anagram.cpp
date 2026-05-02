1class Solution {
2public:
3    int minSteps(string s, string t) {
4        int arr[26] = {0}; 
5        int arr2[26] = {0};
6        for(int i =0 ;i < s.size() ; i++){
7            arr[s[i] - 'a']++;
8            arr2[t[i] -'a']++;
9        }
10        int output = 0 ;
11        for(int i =0 ; i < 26 ; i++){
12            if(arr[i] > arr2[i]){
13                output += arr[i] - arr2[i];
14            }
15        }
16        return output;
17    }
18};