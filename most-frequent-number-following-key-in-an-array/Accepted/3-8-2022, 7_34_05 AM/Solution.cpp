// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<pair<int,int>,int>mp;
        for(int i=0;i<nums.size()-1;i++)
            if(key==nums[i])mp[{nums[i],nums[i+1]}]++;
        int mx=-1,res=0;
        for(auto&[k,v]:mp){
            if(v>mx){
                mx=v;
                res=k.second;
            }
        }
        return res;
    }
};