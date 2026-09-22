class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>s;
        int n=temperatures.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && temperatures[i]>temperatures[s.top()]){
                int x = s.top();
                s.pop();
                res[x]=i-x;
            }
            s.push(i);
        }
        return res;
    }
};
