// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,bool>mp;
        for(auto i:nums){
            if(mp.count(i)) return i;
            mp[i]=1;
        }
        return -1;
    }
};