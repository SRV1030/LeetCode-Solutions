// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:unordered_map<string,vector<pair<int,string>>>mp;
    /** Initialize your data structure here. */
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans="";
        int l=0,r=mp[key].size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(mp[key][m].first<=timestamp){
                ans=mp[key][m].second;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */