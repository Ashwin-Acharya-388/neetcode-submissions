class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int ad : adj[x]){
                indegree[ad]--;
                if(indegree[ad]==0){
                    q.push(ad);
                }
            }
        }
        for(int in : indegree){
            if(in!=0){
                return false;
            }
        }
        return true;
    }
};
