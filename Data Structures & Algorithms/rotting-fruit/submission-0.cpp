class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> dir= {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int row = r + dir[i][0];
                int col = c + dir[i][1];
                if(row<0 || row>=m || col<0 || col>=n || grid[row][col]!=1){
                    continue;
                }
                grid[row][col]=grid[r][c]+1;
                q.push({row,col});
            }
        }
        int maxi = 2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                maxi = max(maxi,grid[i][j]);
            }
        }
        return maxi-2;
    }
};
