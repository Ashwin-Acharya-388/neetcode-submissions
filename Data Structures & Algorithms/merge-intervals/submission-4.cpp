class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0,n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        while(i<n){
            while(i+1<n && intervals[i+1][0]>intervals[i][1]){
                res.push_back(intervals[i]);
                i++;
            }
            int mi=intervals[i][0],ma=intervals[i][1];
            while(i<n && intervals[i][0]<=ma){
                mi=min(intervals[i][0],mi);
                ma=max(intervals[i][1],ma);
                i++;
            }
            res.push_back({mi,ma});
        }
        return res;
    }
};
