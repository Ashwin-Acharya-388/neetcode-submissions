class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(),nums.rend());
        int sum=0;
        for(int n:nums){
            sum+=n;
        }
        if(sum%k!=0){return false;}
        int target=sum/k;
        vector<bool>visit(nums.size());
        return recur(nums,k,target,0,0,visit);
    }
    bool recur(vector<int>& nums, int k,int target,int start,int cursum,vector<bool>& visit){
        if(k==0){
            return true;
        }
        if(cursum==target){
            return recur(nums,k-1,target,0,0,visit);
        }
        for(int i=start;i<nums.size();i++){
            if(visit[i] || cursum+nums[i]>target){
                continue;
            }
            visit[i]=true;
            if(recur(nums,k,target,i+1,cursum+nums[i],visit)){
                return true;
            }
            visit[i]=false;
            
        }
        return false;
    }
};