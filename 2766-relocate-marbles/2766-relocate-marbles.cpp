class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int>mp;
        for(auto&i:nums)++mp[i];
        for(int i=0;i<size(moveFrom);++i)
            if(moveTo[i]!=moveFrom[i] && mp.count(moveFrom[i])){
                mp[moveTo[i]]+=mp[moveFrom[i]];
                mp.erase(moveFrom[i]);
            }   
        vector<int>ans;
        for(auto&[k,v]:mp)ans.push_back(k);
        return ans;
    }
};