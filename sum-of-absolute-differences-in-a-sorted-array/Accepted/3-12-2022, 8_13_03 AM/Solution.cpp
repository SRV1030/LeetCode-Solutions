// https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int>ans;
        int l=0,s=0,n=nums.size();
        for(auto&i:nums)s+=i;
        for(int i=0;i<nums.size();i++){
            l+=nums[i];
            s-=nums[i];
            ans.push_back(s-nums[i]*(n-i-1)-l+nums[i]*(i+1));
        }
        return ans;
    }
};