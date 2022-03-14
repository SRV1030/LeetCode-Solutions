// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int s=nums.size();
        k=k%s;
        if(k==0) return;
        vector<int>v(nums.begin()+k+1,nums.end());
        nums.erase(nums.begin()+k+1,nums.end());
        v.insert(v.end(),nums.begin(),nums.end());
        nums=v;        
    }
};