class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        int res=0;
        vector<bool>visit(n,false);
        for(int i=0;i<n;i++){
            if(visit[i]){
                continue;
            }
            dfs(i,-1,adj,visit);
            res++;
        }
        return res;
    }
    void dfs(int i, int par, vector<vector<int>>&adj,vector<bool>&visit){
        if(visit[i]==true){
            return;
        }
        visit[i]=true;
        for(int ad : adj[i]){
            if(ad==par){
                continue;
            }
            dfs(ad,i,adj,visit);
        }
    }
};
