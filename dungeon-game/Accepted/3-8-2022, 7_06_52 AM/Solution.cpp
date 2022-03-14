// https://leetcode.com/problems/dungeon-game

// https://leetcode.com/problems/dungeon-game/discuss/745340/post-Dedicated-to-beginners-of-DP-or-have-no-clue-how-to-start
class Solution {
public:
    int dp[201][201],r,c;
    int solve(int i,int j, vector<vector<int>>& dun){
        if(i==r || j==c)return INT_MAX;
        if(i==r-1 && j==c-1) return dp[i][j]=dun[i][j]<=0?-dun[i][j]+1:1;
        if(dp[i][j]!=-1)return dp[i][j];
        int rt=solve(i+1,j,dun),dw=solve(i,j+1,dun);
        int need=min(rt,dw)-dun[i][j];
        return dp[i][j]=need<=0?1:need;
    }
    int calculateMinimumHP(vector<vector<int>>& dun) {
        memset(dp,-1,sizeof(dp));
        r=dun.size();
        c=dun[0].size();
        return solve(0,0,dun);
    }
};