// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    int dp[22][22]={};
    int solve(vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]) return dp[i][j];
        int o1=nums[i]+(min(solve(nums,i+2,j),solve(nums,i+1,j-1))),
            o2=nums[j]+(min(solve(nums,i,j-2),solve(nums,i+1,j-1)));
        return dp[i][j]=max(o1,o2);            
    }
    bool PredictTheWinner(vector<int>& nums) {
        int a=solve(nums,0,nums.size()-1);
        int s=0;
        for(auto&i:nums)s+=i;
        return 2*a-s>=0;
    }
};