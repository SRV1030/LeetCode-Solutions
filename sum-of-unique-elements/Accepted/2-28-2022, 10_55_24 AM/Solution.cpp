// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int c=0;
        for(auto&i:nums)mp[i]++;
        for(auto&[k,v]:mp)if(v==1)c+=k;
        return c;
    }
};