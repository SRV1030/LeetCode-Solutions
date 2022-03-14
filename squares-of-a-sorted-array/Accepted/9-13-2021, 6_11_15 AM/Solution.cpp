// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,n=nums.size(),k=0;
        vector<int>v(n);
        for(i=0;i<n && nums[i]<0;i++);
        int j=i-1;
        while(j>=0 && i<n){
            if(abs(nums[i])<abs(nums[j]))v[k++]=nums[i]*nums[i++];
            else v[k++]=nums[j]*nums[j--];
        }
        for(;i<n;i++)v[k++]=nums[i]*nums[i];
        for(;j>=0;j--) v[k++]=nums[j]*nums[j];
        return v;
    }
};