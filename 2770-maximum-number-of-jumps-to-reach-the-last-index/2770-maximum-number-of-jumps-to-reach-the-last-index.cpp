class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums, int tg,int ind){
        if(ind==size(nums)-1) return 0;
        if(dp[ind]!=INT_MIN)return dp[ind];
        int res=-1;
        for(int i=ind+1;i<size(nums);i++){
            if(abs(nums[i]-nums[ind])<=tg){
                int t=solve(nums,tg,i);
                if(t!=-1) res=max(res,1+t);
            }
        }
        return dp[ind]=res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        dp=vector<int>(size(nums)+1,INT_MIN);
        return solve(nums,target,0);
    }
};