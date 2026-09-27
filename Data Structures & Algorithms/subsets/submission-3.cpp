class Solution {
public:
    vector<vector<int>>res;
    vector<int>sub;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return res;
    }
    void dfs(vector<int>& nums,int i){
        if(i>nums.size()){
            return;
        }
        if(i==nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        int x=i+1;
        dfs(nums,x);
        sub.pop_back();
        dfs(nums,x);
    }
};
