// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        for(int i=1;i<j;i++)
            if((nums[i-1]+nums[i+1])%2==0 && (nums[i-1]+nums[i+1])/2==nums[i]){
                swap(nums[i],nums[i+1]);
                i--;
            } 
        return nums;
    }
};