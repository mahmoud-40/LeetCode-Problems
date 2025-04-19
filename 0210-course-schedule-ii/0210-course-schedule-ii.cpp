class Solution {
    vector<vector<int>> graph;  // adjacency list
    vector<int> visited;       // 0=unvisited, 1=visiting, 2=visited
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        for (const auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);  // p[0] depends on p[1]
        }

        visited.resize(numCourses, 0);

        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(i)) return {};
        }

        return result;
    }

    bool dfs(int course) {
        if (visited[course] == 1) return false;  // cycle detected
        if (visited[course] == 2) return true;   // already processed

        visited[course] = 1;  // mark as visiting
        for (int prereq : graph[course]) {
            if (!dfs(prereq)) return false;
        }

        visited[course] = 2;  // mark as completed
        result.push_back(course);
        return true;
    }
};