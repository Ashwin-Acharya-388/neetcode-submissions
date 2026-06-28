class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>subset;
        dfs(subset,0,res,nums,target);
        return res;
    }
private :
    void dfs(vector<int>&subset,int i,vector<vector<int>>&res,vector<int>&nums ,int target){
        if(target==0){
            res.push_back(subset);
            return ;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        subset.push_back(nums[i]);
        dfs(subset,i,res,nums,target-nums[i]);
        subset.pop_back();
        dfs(subset,i+1,res,nums,target);
    }
};
