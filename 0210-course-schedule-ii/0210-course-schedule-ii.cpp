class Solution {
    unordered_map<int, vector<int>> preMap; // course -> prerequisites
    unordered_set<int> visiting;  // current DFS path
    unordered_set<int> visited;   // fully processed courses
    vector<int> result;           // stores the topological order

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Initialize preMap
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        // Check for cycles and build topological order
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return {}; // cycle detected → return empty list
            }
        }

        return result;
    }

    bool dfs(int crs) {
        if (visiting.count(crs)) {
            // Cycle detected
            return false;
        }
        if (visited.count(crs)) {
            // Already processed (no cycle)
            return true;
        }

        visiting.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }

        // Backtrack: remove from visiting, mark as visited
        visiting.erase(crs);
        visited.insert(crs);
        result.push_back(crs); // Add to topological order
        return true;
    }
};