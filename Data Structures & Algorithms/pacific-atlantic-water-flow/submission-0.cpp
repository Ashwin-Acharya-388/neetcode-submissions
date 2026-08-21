class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>>ao(m,vector<bool>(n,false));
        vector<vector<bool>>po(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(!po[i][0]){
                po[i][0]=true;
                q.push({i,0});
            }
        }
        for(int i=0;i<n;i++){
            if(!po[0][i]){
                po[0][i]=true;
                q.push({0,i});
            }
        }
        bfs(heights,po,q,m,n);
        for(int i=0;i<m;i++){
            if(!ao[i][n-1]){
                ao[i][n-1]=true;
                q.push({i,n-1});
            }
        }
        for(int i=0;i<n;i++){
            if(!ao[m-1][i]){
                ao[m-1][i]=true;
                q.push({m-1,i});
            }
        }
        bfs(heights,ao,q,m,n);
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(po[i][j]&&ao[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>&x,queue<pair<int,int>>&q,int m,int n){
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int row = r+dir[i][0];
                int col = c+dir[i][1];
                if(row<0||row>=m||col<0||col>=n||x[row][col]||heights[row][col]<heights[r][c]){
                    continue;
                }
                x[row][col]=true;
                q.push({row,col});
            }

        }
    }
};
