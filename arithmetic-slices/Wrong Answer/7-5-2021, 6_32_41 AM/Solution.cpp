// https://leetcode.com/problems/arithmetic-slices

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<2)return 0;
        int i=0,j=1,d=nums[j]-nums[i],ans=0;
        while(i<nums.size()&& j<nums.size()-1){
            if(nums[j+1]-nums[j]==d)j++;
            else{
                i=j;
                j=j+1;
            }
            if(j-i+1>=3)ans+=j-i+1==3?1:(j-i-1);
        }
        return ans;
    }
};