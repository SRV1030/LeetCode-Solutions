class Solution {
public:
    vector<vector<int>>g;
    int dp[601][101][101];
    int solve(int m,int n,int ind){
        if(ind>=g.size() || (m<=0 && n<=0)) return 0;
        if(dp[ind][m][n]!=-1) return dp[ind][m][n];
        if(g[ind][0]>m || g[ind][1]>n) return dp[ind][m][n]=solve(m,n,ind+1);
        return dp[ind][m][n]=max(1+solve(m-g[ind][0],n-g[ind][1],ind+1),solve(m,n,ind+1));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(auto&i:strs){
            int o=0,z=0;
            for(auto&j:i){
                if(j=='0')z++;
                else o++;
            }
            g.push_back({z,o});
        }
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0);
    }
};

// class Solution {
// public:    
//     int findMaxForm(vector<string>& strs, int m, int n) {
//   vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
//   int numZeroes, numOnes;

//   for (auto &s : strs) {
//     numZeroes = numOnes = 0;
//     // count number of zeroes and ones in current string
//     for (auto c : s) {
//       if (c == '0')
// 	numZeroes++;
//       else if (c == '1')
// 	numOnes++;
//     }

//     // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
//     // from the first few strings up to the current string s
//     // Catch: have to go from bottom right to top left
//     // Why? If a cell in the memo is updated(because s is selected),
//     // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
//     // If we go from top left to bottom right, we would be using results from this iteration => overcounting
//     for (int i = m; i >= numZeroes; i--) {
// 	for (int j = n; j >= numOnes; j--) {
//           memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
// 	}
//     }
//   }
//   return memo[m][n];
// }
// };