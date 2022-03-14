// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

// class Solution {
// public:
//     int minimumDeleteSum(string s1, string s2) {
//         int n1=s1.size(),n2=s2.size(),dp[n1+1][n2+1];
//         for(int i=0;i<=n1;i++){
//             for(int j=0;j<=n2;j++){
//                 if(i==0 && j==0) dp[i][j]=0;
//                 else if(i==0)dp[i][j]=dp[i][j-1]+s2[j-1];
//                 else if(j==0)dp[i][j]=dp[i-1][j]+s1[i-1];
//                 else{
//                     if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
//                     else dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
//                 }
//             }
//         }
//         return dp[n1][n2];
//     }
// };

class Solution {
public:
    int minimumDeleteSum(string t1, string t2) {
        int n1= t1.size(),n2=t2.size(),c=0;
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++)
            for(int j=0;j<=n2;j++){
                if(i==0 || j==0)dp[i][j]=0;
                else{
                    if(t1[i-1]==t2[j-1]) dp[i][j]=t1[i-1]+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        for(auto& i:t1)c+=i;
        for(auto& i:t2)c+=i;
        return c-2*dp[n1][n2];
    }
};