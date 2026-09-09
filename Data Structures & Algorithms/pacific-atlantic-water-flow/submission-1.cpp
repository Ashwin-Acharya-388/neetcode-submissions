class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        vector<vector<bool>>pac(m,vector<bool>(n,false));
        vector<vector<bool>>atl(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            q.push({i,0});
            pac[i][0]=true;
        }
        for(int i=0;i<n;i++){
            q.push({0,i});
            pac[0][i]=true;
        }
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=x.first + dir[i][0];
                int c=x.second + dir[i][1];
                if(r<0||r>=m||c<0||c>=n||pac[r][c]||heights[r][c]<heights[x.first][x.second]){
                    continue;
                }
                pac[r][c]=true;
                q.push({r,c});
            }
        }
        for(int i=0;i<m;i++){
            q.push({i,n-1});
            atl[i][n-1]=true;
        }
        for(int i=0;i<n;i++){
            q.push({m-1,i});
            atl[m-1][i]=true;
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int r=x.first + dir[i][0];
                int c=x.second + dir[i][1];
                if(r<0||r>=m||c<0||c>=n||atl[r][c]||heights[r][c]<heights[x.first][x.second]){
                    continue;
                }
                atl[r][c]=true;
                q.push({r,c});
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
