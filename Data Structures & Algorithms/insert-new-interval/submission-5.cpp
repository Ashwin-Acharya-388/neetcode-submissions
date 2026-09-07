class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int i=0,n=intervals.size();
        if(n==0){
            res.push_back(newInterval);
            return res;
        }
        while(i<n){
            while(i<n && intervals[i][1]<newInterval[0]){
                res.push_back(intervals[i]);
                i++;
            }
            int mi=newInterval[0],ma=newInterval[1];
            while(i<n && intervals[i][0]<=ma){
                mi=min(intervals[i][0],mi);
                ma=max(intervals[i][1],ma);
                i++;
            }
            newInterval[0]=mi,newInterval[1]=ma;
            res.push_back(newInterval);
            while(i<n){
                res.push_back(intervals[i]);
                i++;
            }

        }
        return res;
    }
};
