// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.length(),m=t2.length();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)t[i][j]=0;
                else{
                    if(t1[i]==t2[j])t[i][j]=1+t[i-1][j-1];
                    else t[i][j]=max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[n][m];
    }
};