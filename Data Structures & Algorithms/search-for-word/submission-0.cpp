class Solution {
public:
    int m,n;
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
       vector<vector<bool>>visit(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,m,n,board,word,visit,0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int i,int j,int m,int n,vector<vector<char>>& board, string word,vector<vector<bool>>&visit,int x){
        if(x==word.size()){
            return true;
        }
        if(i>=m||i<0||j>=n||j<0||board[i][j]!=word[x]||visit[i][j]){
            return false;
        }
        visit[i][j]=true;
        bool t = dfs(i+1,j,m,n,board,word,visit,x+1) || dfs(i,j+1,m,n,board,word,visit,x+1) || dfs(i-1,j,m,n,board,word,visit,x+1) || dfs(i,j-1,m,n,board,word,visit,x+1);
        visit[i][j]=false;
        return t;
    }
};