class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ca=0,ma=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(i,j,m,n,ca,grid);
                    ma=max(ma,ca);
                    ca=0;
                }
            }
        }
        return ma;
    }
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int i,int j,int m,int n,int &ca,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            ca++;
            for(int i=0;i<4;i++){
                int row=r+dir[i][0];
                int col=c+dir[i][1];
                if(row<0||row>=m||col<0||col>=n||grid[row][col]==0){
                    continue;
                }
                q.push({row,col});
                grid[row][col]=0;
            }
        }
    }
};
