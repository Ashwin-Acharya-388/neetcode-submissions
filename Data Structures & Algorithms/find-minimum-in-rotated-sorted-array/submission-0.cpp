class Solution {
public:
    int findMin(vector<int>& nums) {
        int beg=0,n=nums.size();
        int end=n-1;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(mid+1<n && nums[mid]>nums[mid+1]){
                return nums[mid+1];
        }
            else if(mid-1>=0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            else if(nums[mid]>nums[end]){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return nums[0];
    }
};