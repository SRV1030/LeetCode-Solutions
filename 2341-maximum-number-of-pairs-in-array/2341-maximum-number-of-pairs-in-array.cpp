class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto&i:nums)++mp[i];
        int c=0,p=0;
        for(auto&[k,v]:mp){
            p+=v/2;
            c+=v%2;
        }
        return {p,c};
    }
};