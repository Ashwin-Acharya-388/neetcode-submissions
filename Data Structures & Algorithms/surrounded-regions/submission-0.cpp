class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>ch(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(!ch[i][0] && board[i][0]=='O'){
                ch[i][0]=true;
                q.push({i,0});
            }
            if(!ch[i][n-1] && board[i][n-1]=='O'){
                ch[i][n-1]=true;
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(!ch[0][i] && board[0][i]=='O'){
                ch[0][i]=true;
                q.push({0,i});
            }
            if(!ch[m-1][i] && board[m-1][i]=='O'){
                ch[m-1][i]=true;
                q.push({m-1,i});
            }
        }
        bfs(board,q,ch,m,n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!ch[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<char>>& board,queue<pair<int,int>>&q,vector<vector<bool>>&ch,int m,int n){
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int row = r+dir[i][0];
                int col = c+dir[i][1];
                if(row<0||row>=m||col<0||col>=n||ch[row][col]||board[row][col]=='X'){
                    continue;
                }
                q.push({row,col});
                ch[row][col]=true;
            }

        }
    }
};