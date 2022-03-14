// https://leetcode.com/problems/sum-of-beauty-in-the-array

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int t=0;
        for(int i=1;i<nums.size();i++)
            if(nums[i]<=nums[i-1]){
                t=1;
                break;
            }
        if(!t)return 2*(nums.size()-2);
        int ans=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1]<nums[i] && nums[i]<nums[i+1])ans++;
        }
        return ans;
    }
};