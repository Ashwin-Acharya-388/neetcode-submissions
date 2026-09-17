class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>>ch(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && search(i,j,0,board,word,ch)){
                        return true;
                }
            }
        }
        return false;
    }
    bool search(int i, int j,int t,vector<vector<char>>& board, string word,vector<vector<bool>>&ch){
        int m=board.size(),n=board[0].size();
        if(i<0||i>=m||j<0||j>=n||t>word.size()-1||ch[i][j]||board[i][j]!=word[t]){
            return false;
        }
        if(t==word.size()-1 && board[i][j]==word[t]){
            return true;
        }
        ch[i][j]=true;
        bool f = search(i+1,j,t+1,board,word,ch) || search(i-1,j,t+1,board,word,ch) || search(i,j+1,t+1,board,word,ch)|| search(i,j-1,t+1,board,word,ch);
    ch[i][j]=false;
    return f;
    }
};
