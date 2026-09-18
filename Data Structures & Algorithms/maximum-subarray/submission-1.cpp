class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,res=INT_MIN;
        for(int n : nums){
            sum=max(sum+n,n);
            res=max(res,sum);
        }
        return res;
    }
};
