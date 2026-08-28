class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0,m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    bfs(m,n,q,grid);
                    res++;
                }
            }
        }
        return res;
    }
    vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int m,int n,queue<pair<int,int>>q,vector<vector<char>>& grid){
        
        while(!q.empty()){
            auto[r,c]=q.front();
        q.pop();
            for(int i=0;i<4;i++){
            int row = r+dir[i][0];
            int col = c+dir[i][1];
            if(row<0||row>=m||col<0||col>=n||grid[row][col]=='0') {
                continue;
            }
            grid[row][col]='0';
            q.push({row,col});
            }
        }
    }
};
