class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  
        int n = matrix[0].size(); 
       
        int l = 0;
        int r = (m - 1);

        int row = -1; 

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) {
                row = mid;
                break;
            }
            else if (matrix[mid][0] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        if(row == -1) return false;

        int x = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
        
        if(x < matrix[row].size() && matrix[row][x] == target){
            return true;
        }

        return false;
    }
};