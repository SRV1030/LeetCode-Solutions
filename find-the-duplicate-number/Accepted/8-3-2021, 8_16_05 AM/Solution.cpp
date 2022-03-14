// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0) return abs(nums[i]);
            nums[abs(nums[i])-1]=-1*nums[abs(nums[i])-1];
        }
        return -1;
    }
};