class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.empty()) return 0;
        int n = cost.size();
        if(cost.size()<=2){
            if(n==1) return cost[0];
            if(n==2) return min(cost[0],cost[1]);
        }
        vector<int>dp(cost.size()+1,0);
        dp[1]=cost[0];
        dp[2]=cost[1];
        for(int i=3;i<=n;i++){
            dp[i]=min(dp[i-1],dp[i-2]) + cost[i-1];
        }
        return min(dp[n],dp[n-1]);
    }
};
