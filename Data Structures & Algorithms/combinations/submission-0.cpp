class Solution {
public:
    vector<vector<int>>res;
    vector<int>sub;
    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,1);
        return res;
    }
    void dfs(int n , int k, int i){
        if(sub.size()==k){
            res.push_back(sub);
            return;
        }
        if(i>n){
            return;
        }
        sub.push_back(i);
        dfs(n,k,i+1);
        sub.pop_back();
        dfs(n,k,i+1);
    }
};