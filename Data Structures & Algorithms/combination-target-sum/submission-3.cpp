class Solution {
public:
    vector<vector<int>>res;
    vector<int>sub;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,target,0);
        return res;
    }
    void dfs(vector<int>& nums, int &target,int i){
        if(target==0){
            res.push_back(sub);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        target-=nums[i];
        sub.push_back(nums[i]);
        dfs(nums,target,i);
        target+=nums[i];
        sub.pop_back();
        dfs(nums,target,i+1);
    }
};
