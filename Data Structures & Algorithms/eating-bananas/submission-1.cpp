class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end()),res=r;
        while(l<=r){
            int mid=(l+r)/2;
            long long hours=0;
            for(int i:piles){
                hours+=ceil((double)i/mid);
            }
            if(hours<=h){
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
