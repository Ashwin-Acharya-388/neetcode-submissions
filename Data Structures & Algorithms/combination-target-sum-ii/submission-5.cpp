class Solution {
public:
    vector<vector<int>>res;
    vector<int>subset;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int target,int i){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        subset.push_back(candidates[i]);
        dfs(candidates,target-candidates[i],i+1);
        subset.pop_back();
        int j=i;
        while(j<candidates.size() && candidates[j]==candidates[i]){j++;}
        dfs(candidates,target,j);
    }
};
