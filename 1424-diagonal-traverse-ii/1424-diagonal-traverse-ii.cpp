class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>mp;
        for(int i=0;i<size(nums);++i)
            for(int j=0;j<size(nums[i]);++j)
                mp[i+j].insert(mp[i+j].begin(),nums[i][j]);
        vector<int>ans;
        for(auto&[k,v]:mp){
            for(auto&i:v)ans.push_back(i);
        }
        return ans;
    }
};