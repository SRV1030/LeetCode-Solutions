class Solution {
public:
    long long numberOfWays(string s) {
        long long dp[4][2]={{0}};
        dp[0][0]=dp[0][1]=1;
        for(auto&i:s){
            for(int j=1;j<=3;j++){
                dp[j][i-'0']+=dp[j-1][1-(i-'0')];
            }
        }
        return dp[3][0]+dp[3][1];
    }
};