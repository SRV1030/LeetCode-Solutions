// https://leetcode.com/problems/coin-change-2

// //Recursion + memoization
// class Solution {
// public:
//     int dp[301][5001];
//     int solve(int i,vector<int>& nums, int target){ 
//         if(i==0 || target<0) return 0;
//         if(target==0) return 1; 
//         if(dp[i][target]!=-1) return dp[i][target];
//         if(nums[i-1]>target) return dp[i][target]=solve(i-1,nums,target);
//         return dp[i][target]=solve(i-1,nums,target)+solve(i,nums,target-nums[i-1]);
//     }
//     int change(int amount, vector<int>& coins) {
//         memset(dp,-1,sizeof(dp));
//         int n = coins.size();
//         if(amount == 0) return 1;
//         if(n==0) return 0;
//         return solve( n, coins,amount);        
//     }
// };

//Top-Down dp
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