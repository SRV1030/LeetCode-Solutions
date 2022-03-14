// https://leetcode.com/problems/coin-change

class Solution {
public:
    int coinChange(vector<int>& c, int a) {
        int n=c.size();
        int t[n+1][a+1];
        for(int i=1;i<=n;i++)t[i][0]=0;
        for(int j=0;j<=a;j++)t[0][j]=INT_MAX;
        for(int j=1;j<=a;j++){
            if(j%c[0])t[1][j]=INT_MAX;
            else t[1][j]=j/c[0];
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=a;j++){
                if(c[i-1]<=j)
                    t[i][j]=min(1+t[i][j-c[i-1]],t[i-1][j]);
                else t[i][j]=t[i-1][j];
            }
        }
        if(t[n][a]==INT_MAX)return -1;
        return t[n][a];
        
    }
};