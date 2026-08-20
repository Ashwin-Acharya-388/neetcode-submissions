class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int INF =2147483647;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int row = r+dirs[i][0];
                int col = c+dirs[i][1];
                if(row<0||row>=m||col<0||col>=n||grid[row][col]!=INF){
                    continue;
                }
                grid[row][col]=grid[r][c]+1;
                q.push({row,col});
            }
        }
    }
};
