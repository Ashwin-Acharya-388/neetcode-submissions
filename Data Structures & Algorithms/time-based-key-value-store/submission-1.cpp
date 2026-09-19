class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string,vector<pair<int,string>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& x = mp[key];
        int l=0, r=x.size()-1;
        string res="";
        while(l<=r){
            int mid=(l+r)/2;
            if(x[mid].first<=timestamp){
                res=x[mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};
