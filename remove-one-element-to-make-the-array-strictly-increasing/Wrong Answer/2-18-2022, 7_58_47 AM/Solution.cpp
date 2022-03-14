// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int c=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]<=nums[i]){
                if(c) return false;
                nums[i]=i==0?-1:nums[i-1];
                if(i>0)i--;
                c++;
            }
        }
        return true;
    }
};