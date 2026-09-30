class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        if(intervals.size()==1){
            return 0;
        }
        int res=0,prev=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=prev){
                prev=intervals[i][1];
            }
            else{
                res++;
                prev=min(prev,intervals[i][1]);
            }
        }
        return res;
    }
};
