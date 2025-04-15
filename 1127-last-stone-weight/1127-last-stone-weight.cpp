class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // 8 7 4 2 1 1

        for(auto stone : stones){
            pq.push(stone);
        }

        while(pq.size() > 1){ // 1 1 1 
            int x = pq.top(); // 8 4 2  
            pq.pop();
            int y = pq.top(); // 7 2 1
            pq.pop();

            if(y != x){
                pq.push(abs(y -x)); // 1 2 1
            }
        }

        return pq.empty()? 0 : pq.top();
    }
};