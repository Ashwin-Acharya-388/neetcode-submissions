class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        int ma=0;
        for(string word : wordDict){
            ma = max(ma,(int)word.size());
        }
        unordered_set<string>ch(wordDict.begin(),wordDict.end());
        for(int i=0;i<n;i++){
            if(!dp[i]){
                continue;
            }
            string st="";
            for(int j=i;j<n && j-i+1<=ma ; j++){
                st+=s[j];
                if(ch.count(st)){
                    dp[j+1]=true;
                }
            }
        }
        return dp[n];
    }
};
