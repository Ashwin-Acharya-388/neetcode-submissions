class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=0;
        for(int w:weights){
            r+=w;
        }
        int res=r;
        while(l<=r){
            int mid=(l+r)/2;
            int sum=0,day=1;
            for(int w : weights){
                if(sum+w>mid){
                    day++;
                    sum=0;
                }
                sum+=w;
            }
            if(day<=days){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};