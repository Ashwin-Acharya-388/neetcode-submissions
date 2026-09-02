class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        int i=0,n=intervals.size();
        sort(intervals.begin(),intervals.end());
        if(n==1){
            return intervals;
        }
        while(i<n){
            while(i+1<n && intervals[i][1]<intervals[i+1][0]){
                res.push_back(intervals[i]);
                i++;
            }
            int ma = intervals[i][1],mi= intervals[i][0];
            while(i+1<n && ma>=intervals[i+1][0]){
                ma=max(ma,intervals[i+1][1]);
                i++;
            }
            res.push_back({mi,ma});
            i++;
        }
        return res;
    }
};
