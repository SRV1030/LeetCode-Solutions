// https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int l=0,r=0,s=0,n=nums.size(),mx=INT_MAX;
        while(r<n){
            while(r<n && s<t) s+=nums[r++];
            while(l<r && s>=t){
                mx=min(mx,r-l);
                s-=nums[l++];
            }
        }
        return mx==INT_MAX?0:mx;
    }
};