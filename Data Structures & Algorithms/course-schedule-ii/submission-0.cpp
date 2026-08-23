class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto& pre:prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(int i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(res.size()==numCourses){
            return res;
        }
        return {};
    }
};
