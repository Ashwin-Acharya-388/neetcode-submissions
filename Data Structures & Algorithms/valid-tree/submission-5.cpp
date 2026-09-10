class Solution {
public:
    unordered_set<int>visit;
    int num=0;
    bool validTree(int n, vector<vector<int>>& edges) {    
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>>adj(n);
        for(auto& ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        bool x = dfs(0,-1,adj);
        return x && (num==n);
    }
    bool dfs(int i, int parent,vector<vector<int>>&adj){
        if(visit.count(i)){
            return false;
        }
        num++;
        visit.insert(i);
        for(int ad : adj[i]){
            if(ad==parent){
                continue;
            }
            if(!dfs(ad,i,adj)){
                return false;
            }
        }
        return true;
    }
};
