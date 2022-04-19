class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto&i:tasks)mp[i]++;
        int r=0;
        for(auto&[k,v]:mp){
            if(v==1) return -1;
            else r+=(v+2)/3;
        }
        return r;
    }
};