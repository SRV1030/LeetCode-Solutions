// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown

class Solution {
    int dp[50001][2][2];
public:
    int solve(int i,vector<int>& prices,bool own,bool cool){
        if(i==prices.size())return 0;
        if(dp[i][own][cool]!=-1)return dp[i][own][cool];
        if(own){
            int o1=prices[i]+solve(i+1,prices,0,1);
            int o2=solve(i+1,prices,1,0);
            return dp[i][own][cool]=max(o1,o2);
        }
        else{
            int o1=cool?0:(-prices[i]+solve(i+1,prices,1,0));
            int o2=solve(i+1,prices,0,0);
            return dp[i][own][cool]=max(o1,o2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,0,0);
    }
};