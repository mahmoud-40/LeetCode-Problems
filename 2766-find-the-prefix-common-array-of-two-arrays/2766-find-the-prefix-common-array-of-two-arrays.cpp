class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    // A : 1 3 2 4
    // B : 3 1 2 4

    // C : 0 2 3 4

        vector<bool> isCommon(A.size(), false);
        int validCounter = 0;
        
        vector<int> result;

        for(int i = 0; i < A.size() ; i++){
            int a = A[i];
            int b = B[i];

            if(isCommon[a]){
                validCounter++;
            }

            isCommon[a] = true;

            if(isCommon[b]){
                validCounter++;
            }

            isCommon[b] = true;

            result.push_back(validCounter);
        }

        return result;
    }
};