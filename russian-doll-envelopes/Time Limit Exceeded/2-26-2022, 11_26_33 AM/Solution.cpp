// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
       int mx=1,n=en.size();
       vector<int>dp(n+1);
        sort(en.begin(),en.end());
        dp[0]=1;
       for(int i=1;i<n;i++){
           dp[i]=1;
           for(int j=0;j<i;j++)
               if(en[j][0]<en[i][0] && en[j][1]<en[i][1] && dp[i]<dp[j]+1)dp[i]=dp[j]+1;
           mx=max(mx,dp[i]);
       } 
       return mx; 
    }
};