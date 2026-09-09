class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=x.first + dir[i][0];
                int c= x.second + dir[i][1];
                if(r<0||r>=m||c<0||c>=n||grid[r][c]!=1){
                    continue;
                }
                grid[r][c]=grid[x.first][x.second] + 1;
                q.push({r,c});
            }
        }
        int mini=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                mini= max(mini,grid[i][j]);
            }
        }
        return mini>0?mini-2:0;
    }
};
