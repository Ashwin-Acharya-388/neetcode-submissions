class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int i=0,x=newInterval[0],y=newInterval[1],n=intervals.size();
        while(i<n && intervals[i][1]<x){
            res.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=y){
            x=min(x,intervals[i][0]);
            y=max(y,intervals[i][1]);
            i++;
        }
        newInterval[0]=x,newInterval[1]=y;
        res.push_back(newInterval);
        while(i<n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
