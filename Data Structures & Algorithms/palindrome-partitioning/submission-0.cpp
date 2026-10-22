class Solution {
public:
    vector<vector<string>>res;
    vector<string>sub;
    vector<vector<string>> partition(string s) {
        recur(s,0);
        return res;
    }
    void recur(string s, int i){
        if(i==s.size()){
            res.push_back(sub);
            return ;
        }
        for(int j=i;j<s.size();j++){
            if(check(s,i,j)){
                sub.push_back(s.substr(i,j-i+1));
                recur(s,j+1);
                sub.pop_back();
            }
        }
    }
    bool check(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
