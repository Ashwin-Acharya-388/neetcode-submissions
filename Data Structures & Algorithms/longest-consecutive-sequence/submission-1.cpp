class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mq;
        int i=1,count=0;
        if(nums.size()==0){
            return 0;
        }
        for(int j=0;j<nums.size();j++){
            mq.insert(nums[j]);
        }
        for(int num:nums){
            if(mq.find(num-1)!=mq.end()){
                continue;
            }
            auto x=mq.find(num+1);
            int run=0;
            while(x!=mq.end()){
                run++;
                i++;
                x=mq.find(num+i);
            }
            if(run>count){
                count = run;
            }
            i=1;
        }
        return count+1;


    }
};
