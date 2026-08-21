class Solution {
public:
    unordered_map<int,vector<int>>prereq;
    unordered_set<int>visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<numCourses;i++){
            prereq[i]={};
        }
        for(const auto &pre:prerequisites){
            prereq[pre[0]].push_back(pre[1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!dfs(i)){
                return false;
            }
        }
        return true;
    }
    bool dfs(int crs){
        if(visited.count(crs)){
            return false;
        }
        if(prereq[crs].empty()){
            return true;
        }
        visited.insert(crs);
        for(int x:prereq[crs]){
            if(!dfs(x)){
                return false;
            }
        }
        visited.erase(crs);
        prereq[crs].clear();
        return true;
    }
};
