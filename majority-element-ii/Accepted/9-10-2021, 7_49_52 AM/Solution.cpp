// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int r=0,l=0,c=0,n=nums.size(),d=n/3;
        vector<int> v;
        sort(nums.begin(),nums.end());
        while(r<n){
            if(nums[r]==nums[l])c++;
            else{
                if(c>d)v.push_back(nums[l]);
                l=r;
                c=0;
                r--;
            }
            r++;
        }
        if(c>d)v.push_back(nums[l]);
        return v;
    }
};