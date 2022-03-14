// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mx=1;
        long long sum=0;
        for(int i=0,j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum+k<nums[j]*(j-i+1))sum-=nums[i++];
            mx=max(mx,j-i+1);
        }
        return mx;
    }
};