class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),resIdx=0,resLen=0;
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(s[i]==s[j] && ((i-j<=2) || dp[i-1][j+1])){
                    dp[i][j] = true;
                    if(i-j+1 > resLen){
                        resLen=i-j+1;
                        resIdx=j;
                    }
                }
            }
        }
        return s.substr(resIdx,resLen);
    }
};
