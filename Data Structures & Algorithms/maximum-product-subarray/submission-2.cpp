class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ma=nums[0],mi=nums[0],res=nums[0];
        if(nums.size()==1){return nums[0];}
        for(int i=1;i<nums.size();i++){
            int temp=ma;
            ma=max(max(ma*nums[i],mi*nums[i]),nums[i]);
            mi=min(min(mi*nums[i],temp*nums[i]),nums[i]);
            res=max(res,ma);
        }
        return res;
    }
};
