class Solution {
public:
    int dp[100005]={};
    int countGoodStrings(int low, int high, int zero, int one,int i=0) {
        if(i>high) return 0;
        if(dp[i]==0) dp[i]=(1+(i>=low?1:0)+countGoodStrings(low,high,zero,one,i+zero)+countGoodStrings(low,high,zero,one,i+one))%1000000007;
        return dp[i]-1;
    }
};