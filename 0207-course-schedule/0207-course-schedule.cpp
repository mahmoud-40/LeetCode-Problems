class Solution {
public:
    // Map each course to its prerequisites
    unordered_map<int, vector<int>> preMap;
    // Store all courses along the current DFS path
    unordered_set<int> vis;


    bool dfs(int crs){
        if(vis.count(crs)){ // cycle exist
            return false;
        }

        if(preMap[crs].empty()){
            return true;
        }

        vis.insert(crs);

        for(auto pre : preMap[crs]){
            if(!dfs(pre)){
                return false;
            }
        }

        vis.erase(crs);
        preMap[crs].clear();

        return true;
    }

    bool canFinish(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for(int crs = 0; crs < numCourses; crs++){
            if(!dfs(crs)){
                return false;
            }
        }

        return true;
    }
};