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