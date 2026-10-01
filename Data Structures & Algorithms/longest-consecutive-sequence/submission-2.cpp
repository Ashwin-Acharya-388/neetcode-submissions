class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int res=0,curr=0;
        vector<int>arr;
        for(int n : s){
        if(!s.count(n-1)){
            int x=n;
            curr=1;
            while(s.count(x+1)){
                curr++;
                x=x+1;
            }
            res=max(res,curr);
            curr=0;
        }
        }
       
        
        return res;
    
    }
};