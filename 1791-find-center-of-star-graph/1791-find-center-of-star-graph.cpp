class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        for(auto&i:edges){
            mp[i[0]]++;
            mp[i[1]]++;            
        }
        int mx=-1,mn=-1;
        for(auto&[k,v]:mp){
            if(v>mx){
                mx=v;
                mn=k;
            }
        }
        return mn;
    }
};