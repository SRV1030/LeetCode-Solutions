// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),l=0,h=n-1,m=0;
        while(m<=h){
            if(nums[m]==0)swap(nums[l++],nums[m]);
            else if(nums[m]==2)swap(nums[h--],nums[m]);
            m++;
        }
    }
};