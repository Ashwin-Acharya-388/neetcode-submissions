class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n= nums.size();
        vector<int>res(2*n);
        res.assign(nums.begin(),nums.end());
        int i=n;
        while(i<2*n){
            res.push_back(nums[i-n]);
            i++;
        }
        return res;
    }
};