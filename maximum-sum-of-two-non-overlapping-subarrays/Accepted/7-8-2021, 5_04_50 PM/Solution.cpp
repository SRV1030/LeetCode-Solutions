// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays

class Solution {
public:
    int solve(vector<int>& nums, int x, int y){
        int n=nums.size();
        int mx1[n],mx2[n],t=0,ans=0;
        for(int i=0;i<n;i++){ 
            if(i<x){
                t+=nums[i];
                mx1[i]=t;
            }
            else{
                t+=nums[i]-nums[i-x];
                mx1[i]=max(t,mx1[i-1]);
            }
        }
        t=0;
        for(int i=n-1;i>=0;i--){ 
            if(i+y>n-1){
                t+=nums[i];
                mx2[i]=t;
            }
            else{
                t+=nums[i]-nums[i+y];
                mx2[i]=max(t,mx2[i+1]);
            }
        }
        for(int i=x-1;i<n-y;i++) ans=max(ans,mx1[i]+mx2[i+1]);
        return ans;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int sd) {        
        return max(solve(nums,f,sd),solve(nums,sd,f));
    }
};