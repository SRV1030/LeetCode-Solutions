class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        int n=coins.size();
        vector<int>dp(a+1,INT_MAX-1);
        dp[0]=0;
        for(int i=1;i<=a;i++)
            for(int j=0;j<n;j++)
                if(i-coins[j]>=0) dp[i]=min(dp[i],dp[i-coins[j]]+1);        
        return dp[a]==INT_MAX-1?-1:dp[a];
    }
};