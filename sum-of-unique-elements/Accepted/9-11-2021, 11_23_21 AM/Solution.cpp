// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int>mp;
        int s=0;
        for(auto&i:nums)mp[i]++;
        for(auto& i:mp)if(i.second==1)s+=i.first;
        return s;
    }
};