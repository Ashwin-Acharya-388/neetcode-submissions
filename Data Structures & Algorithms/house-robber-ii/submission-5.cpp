class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0,rob2=0;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i=0;i<nums.size()-1;i++){
            int temp = max(rob2,rob1+nums[i]);
            rob1=rob2;
            rob2=temp;
        }
        int x = rob2;
        rob1=0,rob2=0;
        for(int i=1;i<nums.size();i++){
            int temp = max(rob2,rob1+nums[i]);
            rob1=rob2;
            rob2=temp;
        }
        int y = rob2;
        return max(x,y);
    }
};
