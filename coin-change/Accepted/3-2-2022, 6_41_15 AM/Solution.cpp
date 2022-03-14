// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        int n=coins.size();
        int t[n+1][a+1];
        for(int i=0;i<=n;i++) t[i][0]=0;
        for(int i=1;i<=a;i++) t[0][i]=INT_MAX-1;
        for(int i=1;i<=a;i++){
            if(i%coins[0]==0)t[1][i]=i/coins[0];
            else t[1][i]=INT_MAX-1;
        }
        for(int i=2;i<=n;i++)
            for(int j=1;j<=a;j++){
                if(coins[i-1]<=j) t[i][j]=min(t[i][j-coins[i-1]]+1,t[i-1][j]);
                else t[i][j]=t[i-1][j];
            }
        return t[n][a]==INT_MAX-1?-1:t[n][a];
    }
};