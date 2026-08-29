class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int INF =2147483647;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto[row,col]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+dir[i][0];
                int c=col+dir[i][1];
                if(r<0||r>=m||c<0||c>=n||grid[r][c]!=INF){
                    continue;
                }
                grid[r][c]=grid[row][col] + 1;
                q.push({r,c});
            }

        }
    }
};
