class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  
        int n = matrix[0].size();  

        int l = 0, r = (m * n) - 1;
    
        while (l <= r){
            int mid = l + (r - l) / 2;
            
            int row = mid / n;
            int col = mid % n;

            int current = matrix[row][col];
            
            if (current == target) {
                return true; 
            } else if (current > target) {
                r = mid - 1;; 
            } else {
                l = mid + 1; 
            }
        }

        return false; 
    }
};

/*
- Time Complexity = m * log(n)
- Space Complexity = o(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++){
            int x = lower_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            if(x < matrix[i].size() && matrix[i][x] == target){
                return true;
            }
        }
        return false;
    }
};
*/