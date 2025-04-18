class Solution {
public:
    bool hasCycle(int node, vector<int>& visited, unordered_map<int, vector<int>>& graph) {
        if (visited[node] == 1) return true;  // Cycle detected (back edge)
        if (visited[node] == 2) return false; // Already processed
        
        visited[node] = 1; // Mark as in recursion stack
        
        for (int neighbor : graph[node]) {
            if (hasCycle(neighbor, visited, graph)) {
                return true;
            }
        }
        
        visited[node] = 2; // Mark as fully processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]); // edge[1] → edge[0]
        }
        
        vector<int> visited(numCourses, 0); // 0=unvisited, 1=visiting, 2=visited
        
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && hasCycle(i, visited, graph)) {
                return false; // Cycle found
            }
        }
        return true;
    }
};