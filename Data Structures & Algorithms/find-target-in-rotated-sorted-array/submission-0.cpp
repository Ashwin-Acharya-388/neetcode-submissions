class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),beg=0,end=n-1,start=0;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(mid+1<n && nums[mid+1]<nums[mid]){
                start=mid+1;
                break;
            }
            else if(mid-1>=0 && nums[mid-1]>nums[mid]){
                start=mid;
                break;
            }
            else if(nums[mid]>nums[n-1]){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        if(target>nums[n-1]){
            beg=0;
            end=start-1;
        }
        else{
            beg=start;
            end=n-1;
        }
        while(beg<=end){
            int mid=(beg+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                beg=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};
