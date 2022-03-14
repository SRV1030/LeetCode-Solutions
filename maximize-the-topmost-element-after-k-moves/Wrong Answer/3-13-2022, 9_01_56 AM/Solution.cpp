// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0)return nums[0];
        if(nums.size()==1)return k%2==0?nums[0]:-1;
        if(k==1 && nums.size()>1)return nums[1];
        if(nums.size()==2)return k==2?nums[0]:max(nums[0],nums[1]);
        if(k>=nums.size())return *max_element(nums.begin(),nums.end());
        int mx=0;
        for(int i=0;i<=k;i++)mx=max(nums[i],mx);
        return mx;
    }
};