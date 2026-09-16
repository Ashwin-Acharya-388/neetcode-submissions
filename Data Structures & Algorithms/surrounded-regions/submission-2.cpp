class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>>bo(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || i==m-1) && board[i][j]=='O' && !bo[i][j]){
                    q.push({i,j});
                    bo[i][j]=true;
                }
                if((j==0 || j==n-1) && board[i][j]=='O' && !bo[i][j]){
                    q.push({i,j});
                    bo[i][j]=true;
                }
            }
        }
        vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto& x = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r= x.first + dir[i][0];
                int c= x.second + dir[i][1];
                if(r<0 || r>=m || c<0 || c>=n ||board[r][c]=='X' || bo[r][c]){
                    continue;
                }
                q.push({r,c});
                bo[r][c]=true;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!bo[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
