class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,grid);
                    res++;
                }
            }
        }
        return res;
    }
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    void bfs(int i, int j , vector<vector<char>>&grid){
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty()){
            auto x= q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r= x.first + dir[i][0];
                int c= x.second + dir[i][1];
                if(r<0||r>=m||c<0||c>=n||grid[r][c]=='0'){
                    continue;
                }
                grid[r][c]='0';
                q.push({r,c});
            }
        }
    }
};
