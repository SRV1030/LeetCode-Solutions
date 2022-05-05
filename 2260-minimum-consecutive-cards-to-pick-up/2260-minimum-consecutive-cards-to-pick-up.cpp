class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        unordered_map<int,int>mp;
        int mn=INT_MAX;
        for(int i=0;i<c.size();i++){
            if(mp.count(c[i]))mn=min(mn,i-mp[c[i]]+1);
            mp[c[i]]=i;
        }
        return mn==INT_MAX?-1:mn;
    }
};