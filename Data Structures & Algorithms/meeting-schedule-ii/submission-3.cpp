/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval&a , Interval&b){
            return a.start<b.start;
        });
        vector<int>prevEnd;
        int res=1,n=intervals.size();
        if(n==0){return 0;}
        if(n==1){return 1;}
        prevEnd.push_back(intervals[0].end);
        for(int i=1;i<n;i++){
            int flag=0;
            for(int j=0;j<prevEnd.size();j++){
                if(intervals[i].start>=prevEnd[j]){
                    prevEnd[j]=intervals[i].end;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                continue;
            }
            else{
                prevEnd.push_back(intervals[i].end);
            }

        }
        return prevEnd.size();
    }
};
