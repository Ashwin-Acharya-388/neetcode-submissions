class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n = asteroids.size(),flag=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()>0 && asteroids[i]<0){
                int res=s.top();
                if(res==abs(asteroids[i])){
                    s.pop();
                    flag=1;
                    break;
                }
                else if(res>abs(asteroids[i])){
                    flag=1;
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(!flag){
                s.push(asteroids[i]);
            }
            flag=0;
        }
        vector<int>resu;
        while(!s.empty()){
            int res=s.top();
            s.pop();
            resu.push_back(res);
        }
        reverse(resu.begin(),resu.end());
        return resu;
    }
};