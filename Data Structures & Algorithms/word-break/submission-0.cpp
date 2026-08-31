class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<bool>dp(n+1,false);
        unordered_set<string>pres(wordDict.begin(),wordDict.end());
        dp[0]=true;
        for(int i=0;i<n;i++){
            if(!dp[i])continue;
            string st ="";
            for(int j=i;j<n;j++){
                st+=s[j];
                if(pres.count(st)){
                    dp[j+1]=true;
                }
            }
        }
        return dp[n];
    }
};
