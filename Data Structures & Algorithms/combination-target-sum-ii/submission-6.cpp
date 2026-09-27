class Solution {
public:
    vector<vector<int>>res;
    vector<int>sub;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return res;
    }
    void dfs(vector<int>& candidates, int &target,int i){
        if(target==0){
            res.push_back(sub);
            return;
        }
        if(i==candidates.size() || target<0){
            return;
        }
        sub.push_back(candidates[i]);
        target-=candidates[i];
        dfs(candidates,target,i+1);
        sub.pop_back();
        int x = candidates[i];
        target+=candidates[i];
        while(i+1<candidates.size() && candidates[i+1]==x){
            i++;
        }
        dfs(candidates,target,i+1);
    }
};
