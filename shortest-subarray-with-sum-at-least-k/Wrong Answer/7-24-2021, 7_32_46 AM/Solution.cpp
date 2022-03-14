// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int s=0,l=0,r=0,n=nums.size(),mn=INT_MAX;
        while(r<n){
            while(r<n && s<k)s+=nums[r++];
            while(l<r && s>=k){
                mn=min(mn,r-l);
                s-=nums[l++];
            }
        }
        return mn==INT_MAX?-1:mn;
    }
};