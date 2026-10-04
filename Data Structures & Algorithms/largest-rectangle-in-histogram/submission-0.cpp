class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>s;
        int res=0,flag=0,n=heights.size();
        auto x = pair{0,0};
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[i]<s.top().second){
                flag=1;
                x=s.top();
                s.pop();
                int hi= (i-x.first) * x.second;
                res=max(res,hi);
            }
            if(flag){
                s.push({x.first,heights[i]});
            }
            else{
                s.push({i,heights[i]});
            }
            flag=0;
        }
        while(!s.empty()){
            x=s.top();
            s.pop();
            int hi= (n-x.first)*x.second;
            res=max(hi,res);
        }
        return res;
    }
};
