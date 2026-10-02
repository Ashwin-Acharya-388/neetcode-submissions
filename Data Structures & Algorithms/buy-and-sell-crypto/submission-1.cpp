class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0,r=1,res=0;
        while(r<prices.size()){
            while(l<r && (prices[r]-prices[l])<0){
                l++;
            }
            res=max(prices[r]-prices[l],res);
            r++;
        }
        return res;
    }
};
