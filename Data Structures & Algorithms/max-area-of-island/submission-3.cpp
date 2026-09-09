class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ma=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ma=max(ma,dfs(i,j,grid));
                }
            }
        }
        return ma;
    }
    int dfs(int i, int j, vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size();        
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        return 1 + dfs(i+1,j,grid) + dfs(i-1,j,grid)+ dfs(i,j+1,grid) + dfs(i,j-1,grid) ;
    }
};
