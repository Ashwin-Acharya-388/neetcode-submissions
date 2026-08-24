class Solution {
public:
    unordered_set<int>visit;
    bool validTree(int n, vector<vector<int>>& edges) {
        if((edges.size()+1)!=n){
            return false;
        }
    vector<vector<int>>adj(n);
    for(auto& ed : edges){
        adj[ed[0]].push_back(ed[1]);
        adj[ed[1]].push_back(ed[0]);
    }
    return dfs(adj,0,-1) && visit.size()==n;
    }
    bool dfs(vector<vector<int>>adj,int i,int prev){
        if(visit.count(i)){
            return false;
        }
        visit.insert(i);
        for(int x : adj[i]){
            if(x==prev){
                continue;
            }
            if(!dfs(adj,x,i)){
                return false;
            }
        }
        return true;
    }
};
