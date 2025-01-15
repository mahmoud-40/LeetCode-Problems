class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       // A: 1 3 2 4
       // B: 3 1 2 4

       // C: 0 2 3 4

       // A: 2 3 1
       // B: 3 1 2
       
       // C: 0 1 3

        map<int, bool> isCommon;
        vector<int> C;

        int validCounter = 0;

        for(int i = 0; i < A.size() ; i++){
            int a = A[i];
            int b = B[i];

            if(isCommon[a]){
                validCounter++;
                // isCommon[a] = false;
            }
            isCommon[a] = true;

            if(isCommon[b]){
                validCounter++;
                // isCommon[b] = false;
            }
            isCommon[b] = true;

            C.push_back(validCounter);
        }

        return C;
    }
};