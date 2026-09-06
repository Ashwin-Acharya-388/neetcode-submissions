class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int num :nums){
            if(mp[num]==0){
                mp[num]=1;
            }
            else{
                mp[num]++;
            }
        }
        int ma=0,l;
        vector<int>res;
        while(k>0){
            for(auto num : mp){
                if(num.second>ma){
                    ma=num.second;
                    l=num.first;
                }
            }
            res.push_back(l);
            mp.erase(l);
            k--;
            ma=0;
        }
        return res;
    }
};
