class Solution {
public:
    vector<vector<int>>res;
    vector<int>subset;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>pick(nums.size(),false);
        dfs(nums,pick);
        return res;
    }
private: 
    void dfs(vector<int>&nums,vector<bool>&pick){
        if(subset.size()==nums.size()){
            res.push_back(subset);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
            subset.push_back(nums[i]);
            pick[i]=true;
            dfs(nums,pick);
            subset.pop_back();
            pick[i]=false;
        }
            }    }
};
