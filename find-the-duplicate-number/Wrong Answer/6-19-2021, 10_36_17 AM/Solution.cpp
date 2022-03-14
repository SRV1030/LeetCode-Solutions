// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int e=1;
        for(auto i:nums){
            if(e!=i)return i;
           e++;
        }
        return -1;
    }
};