// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()==0 || k==0) return 0;
        int n=prices.size();
        int dp[n+1][2][k+1];//days,own,transactions
        memset(dp,-1,sizeof(dp));
        for(int days=n-1;days>=0;days--){
            for(int trans=0;trans<=k;trans++){
                if(days==n-1){
                    dp[days][0][trans]=0;
                    dp[days][1][trans]=trans>=1?prices[days]:0;
                }
                else{
                    dp[days][0][trans]=max(dp[days+1][0][trans],(-prices[days]+dp[days+1][1][trans]));
                    dp[days][1][trans]=trans>=1?max(dp[days+1][1][trans],(prices[days]+dp[days+1][0][trans-1])):0;
                }
            }
        }
        return dp[0][0][k]==-1?0:dp[0][0][k];
    }
};