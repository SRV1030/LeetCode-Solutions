// https://leetcode.com/problems/champagne-tower

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[query_row+1][query_glass+2];
        memset(dp,0,sizeof(dp));
        dp[0][0]= poured;
        for(int i=0;i<query_row;i++){
            for(int j=0;j<=query_glass;j++){
               double res=max(0.0,(dp[i][j]-1.0)/2.0);
                dp[i+1][j]+=res;
                dp[i+1][j+1]+=res;
            }
        }
        return min(1.0,dp[query_row][query_glass]);
    }
};