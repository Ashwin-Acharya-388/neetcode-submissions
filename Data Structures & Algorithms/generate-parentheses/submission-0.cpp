class Solution {
public:
    vector<string>res;
    string sub;
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0);
        return res;
    }
    void dfs(int n , int out , int in){
        if(out==n && in==n){
            res.push_back(sub);
            return;
        }
        if(out<n){
            sub.push_back('(');
            dfs(n,out+1,in);
            sub.pop_back();
        }
        if(in<out){
            sub.push_back(')');
            dfs(n,out,in+1);
            sub.pop_back();
        }
    }
};
