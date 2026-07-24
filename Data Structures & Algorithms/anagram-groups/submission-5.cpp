class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        unordered_map<string,vector<string>>res;
        for(auto& s:strs){
            vector<int>count(26,0);
            for(auto&c : s){
                count[c-'a']++;
            }
            string st = to_string(count[0]);
            for(int i=1;i<26;i++){
                st+= "," + to_string(count[i]);
            }
            res[st].push_back(s);
        }
        for(auto &pair : res){
            result.push_back(pair.second);
        }
        return result;
    }
};
