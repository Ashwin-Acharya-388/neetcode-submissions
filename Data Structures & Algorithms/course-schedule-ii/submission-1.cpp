class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses);
        vector<vector<int>>adj(numCourses);
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
        vector<int>res;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            res.push_back(x);
            for(int ad: adj[x]){
                indegree[ad]--;
                if(indegree[ad]==0){
                    q.push(ad);
                }
            }
        }
        if(res.size()!=numCourses){
            return {};
        }
        return res;
    }
};
