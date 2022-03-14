// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<h){
            if(nums[m]==0) swap(nums[m++],nums[l++]);
            else if(nums[m]==2) swap(nums[m],nums[h--]);
            else m++;
        }
    }
};