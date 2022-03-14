// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:vector<vector<int>>dp;
    int md=1000000007;
    int util(int d,int f,int t){
        if(d==0 && t==0) return 1;
        if(d==0 || t<0) return 0;
        if(dp[d][t]!=-1)return dp[d][t];
        int ans=0;
        for(int i=1;i<=f;i++)
            ans=(ans%md+util(d-1,f,t-i)%md)%md;
        
        return dp[d][t]=ans;
    }
    int numRollsToTarget(int d, int f, int target) {
        dp=vector<vector<int>>(d+1,vector<int>(target+1,-1));
        return util(d,f,target);
    }
};