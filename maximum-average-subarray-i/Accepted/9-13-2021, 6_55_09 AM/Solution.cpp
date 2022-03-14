// https://leetcode.com/problems/maximum-average-subarray-i

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx=0.0,s=0.0;
        int n=nums.size();
        for(int i=0;i<k;i++)s+=nums[i];
        mx=s/((double)k);
        for(int i=0;i<n-k;i++){
            s-=nums[i];
            s+=nums[i+k];
            mx=max(mx,s/((double)k));
        }
        return mx;
    }
};