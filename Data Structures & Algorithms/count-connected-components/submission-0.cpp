class Solution {
public:
    unordered_set<int>visit;
    unordered_set<int>vis;
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(vis.count(i)){
                continue;
            }
            dfs(adj,i);
            visit.clear();
            res++;
        }
        return res;
    }
    void dfs(vector<vector<int>>&adj,int i){
        if(visit.count(i)){
            return;
        }
        visit.insert(i);
        vis.insert(i);
        for(int x : adj[i]){
            if(visit.count(x)){
                continue;
            }
            dfs(adj,x);
        }
    }

};
