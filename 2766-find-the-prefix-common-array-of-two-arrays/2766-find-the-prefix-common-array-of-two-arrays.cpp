class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int, bool> isCommon;
        vector<int> result; // C

        int validCounter = 0;

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