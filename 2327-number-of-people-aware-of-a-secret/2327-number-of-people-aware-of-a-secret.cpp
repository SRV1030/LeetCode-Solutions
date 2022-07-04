class Solution {
public:
    int md=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
       vector<long>dp(n+1);
        dp[1]=1;
        int res=0,share=0;
        for(int i=2;i<=n;++i)dp[i]=share=(share%md+dp[max(0,i-delay)]%md-dp[max(0,i-forget)]%md+md)%md;
        for(int i=n-forget+1;i<=n;++i)res=(res+dp[i])%md;
        return res;
    }
};