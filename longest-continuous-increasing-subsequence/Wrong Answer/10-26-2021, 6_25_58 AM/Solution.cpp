// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx=1,c=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i])c++;
            else{
                if(c>mx)mx=c;
                c=1;
            }
        }
        return mx;
    }
};