// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int c=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i].size()+nums[j].size()!=target.size())continue;
                if(nums[i]+nums[j]==target)c++;
                if(nums[j]+nums[i]==target)c++;
            }
        }
        return c;
    }
};