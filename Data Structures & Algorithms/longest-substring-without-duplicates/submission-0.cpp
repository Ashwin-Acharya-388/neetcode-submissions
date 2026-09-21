class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,res=0,n=s.size();
        unordered_set<char>mp;
        while(r<n){
            while(mp.count(s[r])){
                mp.erase(s[l]);
                l++;
            }
            mp.insert(s[r]);
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};
