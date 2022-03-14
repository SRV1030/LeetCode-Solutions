// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int x=*min_element(nums.begin(),nums.end());
        int ind = (find(nums.begin(),nums.end(),x)-nums.begin());
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        while(i<=j){
            int m=(i+j)/2;
            if(nums[m]==target) return(m+ind)%nums.size();
            else if(nums[m]>target) j=m-1;
            else i=m+1;
        }
        return -1;
    }
};