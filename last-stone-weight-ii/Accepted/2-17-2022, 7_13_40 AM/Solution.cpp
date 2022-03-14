// https://leetcode.com/problems/last-stone-weight-ii

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int s=0,n=stones.size();
        for(auto&i:stones)s+=i;
        bool dp[n+1][s+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=s;j++){
                if(j==0)dp[i][j]=true;
                else if(i==0) dp[i][j]=false;
                else{
                    if(stones[i-1]<=j)dp[i][j]=dp[i-1][j]||dp[i-1][j-stones[i-1]];
                    else dp[i][j]=dp[i-1][j];
                }                
            }
        int mn=INT_MAX;
        for(int j=0;j<=s;j++)if(dp[n][j])mn=min(mn,abs(s-2*j));
        return mn;            
    }
};