// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>vis(nums.size()+1);
        vector<int> ans;
        for(auto i:nums){
            if(vis[i]) ans.push_back(i);
            else vis[i]=1;
        }
        return ans;
    }
};