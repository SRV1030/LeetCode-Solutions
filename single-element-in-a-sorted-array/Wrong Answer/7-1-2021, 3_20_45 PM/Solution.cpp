// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]!=nums[i+1]) return nums[i];
            if(nums[j]!=nums[j-1]) return nums[j];
            i+=2;
            j-=2;
        }
        return -1;        
        
    }
};