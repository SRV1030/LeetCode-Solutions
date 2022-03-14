// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(n==2) return nums[0]>nums[1]?0:1;
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m+1<n && m-1>=0 && nums[m]>nums[m+1] && nums[m]>nums[m-1]) return m;
            else if(m-1>=0 && nums[m-1]>nums[m])r=m-1;
            else l=m+1;
        }
        return l-1;
    }
};