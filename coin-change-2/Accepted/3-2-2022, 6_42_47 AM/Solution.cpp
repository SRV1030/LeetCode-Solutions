// https://leetcode.com/problems/coin-change-2

class Solution {
public:
    int change(int a, vector<int>& c) {
        int n=c.size();
        int t[n+1][a+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=a;j++){
                if(j==0) t[i][j]=1;
                else if(i==0) t[i][j]=0;
                else{
                    if(c[i-1]<=j)t[i][j]=t[i-1][j]+t[i][j-c[i-1]];
                    else t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][a];
    }
};