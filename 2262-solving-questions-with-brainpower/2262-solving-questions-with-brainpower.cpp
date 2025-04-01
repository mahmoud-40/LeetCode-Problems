class Solution {
public:
    static const int N = 1e5 + 20;
    long long cache[N];

    long long rec(long long i, vector<vector<int>>& questions){
        if(i >= questions.size()){
            return 0;
        }

        if(cache[i] != -1){
            return cache[i];
        }

        long long skip = 0, take = 0;

        skip = rec(i + 1, questions);
        
        take = rec(i + questions[i][1] + 1, questions) + questions[i][0];

        return cache[i] = max(skip, take);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        memset(cache, -1, sizeof(cache));
        return rec(0, questions);
    }
};