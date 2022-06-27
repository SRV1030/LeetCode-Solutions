// class Solution {
// public:
//     int md=1e9+7;
//     vector<vector<int>>dp;
//     int solve(int n,bool f){
//         if(n==1) return 1;
//         if(dp[n][f]!=-1) return dp[n][f];
//         if(f) return dp[n][f]=solve(n-1,0);
//         return dp[n][f]=(solve(n-1,0)%md+solve(n-1,1)%md)%md;
        
//     }
//     int countHousePlacements(int n) {
//         dp.resize(2*n,vector<int>(2,-1));
//         long res= (solve(n,0)%md+solve(n,1)%md)%md;
//         return (res%md*res%md)%md;
//     }
// };
class Solution {
public:
 int countHousePlacements(int n) {
        int a = 1, b = 1, c = 2, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            c = (a + b) % mod;
            a = b;
            b = c;
        }
        return 1L * b * b % mod;
    }
};