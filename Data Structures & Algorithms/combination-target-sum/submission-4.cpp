class Solution {
public:
    vector<vector<int>>res;
    vector<int>sub;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(nums,target,0);
        return res;
    }
    void dfs(vector<int>& nums, int target,int i){
        if(i==nums.size() || target<0){
            return;
        }
        if(target==0){
            res.push_back(sub);
            return;
        }
        sub.push_back( nums[i]);
        target=target-nums[i];
        dfs(nums,target,i);
        sub.pop_back();
        target=target+nums[i];
        dfs(nums,target,i+1);
    }
};
