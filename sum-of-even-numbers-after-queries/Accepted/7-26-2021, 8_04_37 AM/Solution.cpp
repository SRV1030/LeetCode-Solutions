// https://leetcode.com/problems/sum-of-even-numbers-after-queries

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        int se=0;
        for(auto& i:nums) if(i%2==0)se+=i;
        for(auto& i:q){
            int v=i[0],ind=i[1];
            if(nums[ind]%2==0)se-=nums[ind];
            nums[ind]+=v;
            if(nums[ind]%2==0)se+=nums[ind];
            ans.push_back(se);
        }
        return ans;
    }
};