class Solution {
public:
    vector<vector<int>>res;
    vector<int>sub;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>pick(nums.size(),false);
        dfs(pick,nums);
        return res;
    }
    void dfs(vector<bool>&pick,vector<int>& nums){
        if(sub.size()==nums.size()){
            res.push_back(sub);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!pick[i]){
                sub.push_back(nums[i]);
                pick[i]=true;
                dfs(pick,nums);
                pick[i]=false;
                sub.pop_back();
            }
        }
    }
};
