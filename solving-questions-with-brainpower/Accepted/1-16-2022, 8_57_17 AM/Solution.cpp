// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long>dp(n);
        for(int i=n-1;i>=0;i--){
            int p=q[i][0];
            int b=q[i][1];
            if(i+b+1<n){
                dp[i]=max(p+dp[i+b+1],dp[i+1]);
            }else{
                if(i+1>=n)
                dp[i]=p;
                else
                    dp[i]=max((long long)p,dp[i+1]);
            }
        }
        long long ans=0;
        for(auto x:dp){
            ans=max(ans,x);
        }
        return ans;
    }
};