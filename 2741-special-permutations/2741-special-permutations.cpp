class Solution {
public:
    int dp[14][(1<<14)+1];
    int md=1e9+7;
    int solve(vector<int>&nums,int pv,int msk){
        if(msk==((1<<size(nums))-1)) return 1;
        if(dp[pv][msk]!=-1)return dp[pv][msk];
        int ans=0;
        for(int i=0;i<size(nums);++i)
            if((msk&(1<<i))==0 && (nums[pv]%nums[i]==0 || nums[i]%nums[pv]==0)){
                ans+=(solve(nums,i,msk|1<<i))%md;
                ans%=md;
            }
        return dp[pv][msk]=ans;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<size(nums);++i){
            ans+=(solve(nums,i,1<<i))%md;
            ans%=md;
        }
        return ans%md;
    }
};