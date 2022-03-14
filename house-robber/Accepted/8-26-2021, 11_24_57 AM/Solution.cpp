// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int a=nums[0],b=max(nums[0],nums[1]),c=b;
        for(int i=2;i<nums.size();i++){
             c=max(a+nums[i],b);
            a=b;
            b=c;
        }
        return c;
        
    }
};