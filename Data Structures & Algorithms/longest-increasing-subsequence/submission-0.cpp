class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int n=nums.size(),res=1;
        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n;j++){
                if(nums[j]>nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                res=max(res,dp[i]);
            }
        }
        return res;
    }
};
