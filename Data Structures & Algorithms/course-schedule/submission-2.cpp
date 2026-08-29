class Solution {
public:
    unordered_set<int>visit;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>prereq(numCourses);
        for(auto &pre : prerequisites){
            prereq[pre[0]].push_back(pre[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,prereq)){
                return false;
            }
        }
        return true;
    }
    bool dfs(int i,vector<vector<int>>&prereq){
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
        visit.erase(i);
        prereq[i].clear();
        return true;
    }
};
