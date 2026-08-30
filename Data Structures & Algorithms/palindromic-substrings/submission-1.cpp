class Solution {
public:
    int countSubstrings(string s) {
        int res=0,n=s.size();
        vector<vector<bool>>pal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || pal[i+1][j-1])){
                    pal[i][j]=true;
                    res++;
                }
            }
        }
        return res;
    }
};
