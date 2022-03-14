// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto&i:nums){
            int x= i>0?i:-i;
            if(nums[x-1]>0)nums[x-1]*=-1;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)ans.push_back(i+1);
        return ans;
    }
};