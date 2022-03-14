// https://leetcode.com/problems/maximum-students-taking-exam

class Solution {
public:
    int n,m;
    int ans = 0;
    int dp[9][(1<<8)+2];  //dp[i][mask]: we are in row i(i is from [1,9]), state is mask
    int avail[9];  //avail[i] is the mask representing available seats in row i
        
    int maxStudents(vector<vector<char>>& seats) {
        n = seats.size(); m = seats[0].size();
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (seats[i-1][j] == '.') {
                    avail[i] |= (1<<j);
                }
            }
        }
        
        for (int mask = 0; mask < (1<<m); mask++) {
            dp[0][mask] = 0;  //initialize all illegal states with 0
        }
        
        for (int i = 1; i <= n; i++) {  //now we are at row i
            for (int premask = 0; premask < (1<<m); premask++) {
                if (dp[i-1][premask] == -1) continue;
                for (int mask = 0; mask < (1<<m); mask++) {
                    if ((mask & avail[i]) != mask) continue;
                    if (mask&(mask>>1)) continue;  //if there is adjacent 1
                    
                    /*checking this row and last row*/
                    if (mask&(premask<<1) || mask&(premask>>1)) continue;
                    dp[i][mask] = max(dp[i][mask], dp[i-1][premask] + __builtin_popcount(mask));
                }
            }
        }
        
        for (int mask = 0; mask < (1<<m); mask++) {
            ans = max(ans, dp[n][mask]);
        }
        return ans;
    }
};