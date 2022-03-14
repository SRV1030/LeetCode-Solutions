// https://leetcode.com/problems/wildcard-matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int n1=s.size(),n2=p.size();
        bool dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 && j==0)dp[i][j]=true;
                else if(i==0)dp[i][j]=p[j-1]=='*' && dp[i][j-1];
                else if(j==0) dp[i][j]=false;
                else if(p[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else if(s[i-1]==p[j-1]||p[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=false;                
            }
        }
        return dp[n1][n2];
    }
};