class Solution {
public:
    vector<int>memo;
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        memo.assign(nums.size(),-1);
        int x = dp(nums,0,nums.size()-1);
        memo.assign(nums.size(),-1);
        int y = dp(nums,1,nums.size());
        return max(x,y);
        }
        int dp(vector<int>& nums,int i,int n){
            if(i>=n){
                return false;
            }
            if(memo[i]!=-1){
                return memo[i];
            }
            memo[i]=max(dp(nums,i+1,n),dp(nums,i+2,n)+nums[i]);
            return memo[i];
        }   
    
};
