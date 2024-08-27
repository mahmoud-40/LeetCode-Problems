class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].emplace_back(v, prob);
            adj[v].emplace_back(u, prob); 
        }
        
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1.0, start_node}); 
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        while (!maxHeap.empty()) {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();

            if (node == end_node) {
                return prob;
            }

            for (const auto& [neighbor, edgeProb] : adj[node]) {
                double newProb = prob * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    maxHeap.push({newProb, neighbor});
                }
            }
        }

        return 0.0;
    }
};