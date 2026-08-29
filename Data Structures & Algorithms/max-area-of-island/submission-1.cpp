class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int marea=0,carea=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,m,n,grid,carea);
                    marea=max(carea,marea);
                    carea=0;
                }
            }
        }
        return marea;
    }
    void dfs(int i,int j,int m,int n,vector<vector<int>>& grid,int &carea){
        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0){
            return;
        }
        carea++;
        grid[i][j]=0;
        dfs(i+1,j,m,n,grid,carea);
        dfs(i-1,j,m,n,grid,carea);
        dfs(i,j+1,m,n,grid,carea);
        dfs(i,j-1,m,n,grid,carea);

    }
};
