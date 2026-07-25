class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>res;
        int mul=1,count =0;
        for(int n:nums){
            if(n==0){
                count++;
                continue;
            }
            mul*=n;
        }
        if(count==1){
            for(int n:nums){
                if(n==0){
                    res.push_back(mul);
                }
                else{
                    res.push_back(0);
                }
            }
            return res;
        }
        if(count>1){
            for(int n:nums){
                res.push_back(0);
            }
            return res;
        }


        
        for(int n:nums){
            res.push_back(mul/n);
        }
        return res;
    }
};
