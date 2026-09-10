class Solution {
public:
    unordered_set<int>visit;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>prereq(numCourses);
        for(auto& pre : prerequisites){
            prereq[pre[1]].push_back(pre[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,prereq)){
                return false;
            }
            visit.clear();
        }
        return true;
    }
    bool dfs(int i, vector<vector<int>>&prereq){
        if(visit.count(i)){
            return false;
        }
        if(prereq[i].empty()){
            return true;
        }
        visit.insert(i);
        for(int pre : prereq[i]){
            if(!dfs(pre,prereq)){
                return false;
            }
        }
        prereq[i].clear();
        visit.erase(i);
        return true;
    }
};
