class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int r = grid.size(),c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,r,c,grid);
                    res++;
                }
            }
        }
        return res;
    }
    vector<vector<int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
    void dfs(int i,int j, int r, int c , vector<vector<char>>&grid){
         if(i<0||i>=r||j<0||j>=c||grid[i][j]!='1'){
            return;
        }
        grid[i][j]='0';
        dfs(i+1,j,r,c,grid);
        dfs(i-1,j,r,c,grid);
        dfs(i,j+1,r,c,grid);
        dfs(i,j-1,r,c,grid);
    }
};
