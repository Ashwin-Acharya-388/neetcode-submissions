class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>pal(s.size(),vector<bool>(s.size(),false));
        int resIdx=0,resLen=0,n=s.size();
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || pal[i+1][j-1])){
                    pal[i][j]=true;
                    if(j-i+1 >resLen){
                        resIdx=i;
                        resLen = j-i+1;
                    }
                }
            }
        }
        return s.substr(resIdx,resLen);
    }
};
