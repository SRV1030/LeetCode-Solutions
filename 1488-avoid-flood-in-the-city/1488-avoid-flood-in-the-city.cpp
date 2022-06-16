class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int>res(size(rains),-1);
        unordered_map<int,int>mp;
        set<int>z;
        for(int i=0;i<size(rains);++i){
            if(!rains[i]){
                res[i]=1;
                z.insert(i);
            }else{
                if(mp.count(rains[i])){
                    int prev=mp[rains[i]];
                    auto it=z.upper_bound(prev);
                    if(it==end(z))return{};
                    res[*it]=rains[i];
                    z.erase(it);
                }
                mp[rains[i]]=i;
            }
        }
        return res;
    }
};