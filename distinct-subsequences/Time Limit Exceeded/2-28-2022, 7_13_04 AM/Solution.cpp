// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int dp[1001][1001],ns,nt;
    int solve(string s, string t,int i,int j){
        if(j==nt) return 1;
        if(i==ns) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=solve(s,t,i+1,j+1)+solve(s,t,i+1,j);//include + exclude
        else return dp[i][j]= solve(s,t,i+1,j); // exclude
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        ns=s.size();
        nt=t.size();
        if(s==t) return 1;
        return solve(s,t,0,0);
    }
};

// https://www.youtube.com/watch?v=HtLVAvIGikU