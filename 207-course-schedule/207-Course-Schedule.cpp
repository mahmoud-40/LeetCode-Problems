class Solution {
public:
    // bool hasCycle(int node, vector<int>& visited, unordered_map<int, vector<int>>& graph) {
    //     if (visited[node] == 1) return true;  // Cycle detected (back edge)
    //     if (visited[node] == 2) return false; // Already processed
        
    //     visited[node] = 1; // Mark as in recursion stack
        
    //     for (int neighbor : graph[node]) {
    //         if (hasCycle(neighbor, visited, graph)) {
    //             return true;
    //         }
    //     }
        
    //     visited[node] = 2; // Mark as fully processed
    //     return false;
    // }

    // // DFS Approach
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     unordered_map<int, vector<int>> graph;
    //     for (const auto& edge : prerequisites) {
    //         graph[edge[1]].push_back(edge[0]); // edge[1] → edge[0]
    //     }
        
    //     vector<int> visited(numCourses, 0); // 0=unvisited, 1=visiting, 2=visited
        
    //     for (int i = 0; i < numCourses; ++i) {
    //         if (visited[i] == 0 && hasCycle(i, visited, graph)) {
    //             return false; // Cycle found
    //         }
    //     }
    //     return true;
    // }

    // BFS 
    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> graph;
        vector<int> inDegree(numCourses, 0);
        
        for (const auto& edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];
            graph[prerequisite].insert(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; 
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;

            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses;
    }
};