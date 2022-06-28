class Solution {
public:
    int dp[10001][7][7]={};
    int distinctSequences(int n,int p=0,int pp=0) {
        if(n==0) return 1;
        if(!dp[n][p][pp]){
            for(int i=1;i<7;++i){
                if(i!=p && i!=pp && (p==0 || gcd(i,p)==1)) dp[n][p][pp]=(dp[n][p][pp]+distinctSequences(n-1,i,p))%1000000007;
            }
        }
        return dp[n][p][pp];
    }
};