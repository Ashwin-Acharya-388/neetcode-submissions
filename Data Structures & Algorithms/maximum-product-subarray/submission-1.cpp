class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cmax=1,cmin=1,res=nums[0];
        for(int n:nums){
            int tmp=cmax;
            cmax=max(max(n*cmax,n*cmin),n);
            cmin=min(min(n*tmp,n*cmin),n);
            res=max(res,cmax);
        }
        return res;
    }
};
