class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        int mx=0;
        for(auto&i:nums){
            ++mp[i];
            mx=max(mx,mp[i]);
        }
        vector<vector<int>>ans(mx);
        for(int i=0;i<mx;++i){
            for(auto&[k,v]:mp){
                if(v>0)ans[i].push_back(k);
                --v;
            }
        }
        return ans;
    }
};