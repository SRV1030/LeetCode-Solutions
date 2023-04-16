class Solution {
public:
    int n;
    int dp[1001][2001];
    int solve(vector<vector<int>>& piles, int ind,int c){
        if(ind>=n || c<0) return 0;
        if(dp[ind][c]!=-1) return dp[ind][c];
        int mx=solve(piles,ind+1,c),sm=0,sz=piles[ind].size();
        for(int i=0;i<min(sz,c);i++){
            sm+=piles[ind][i];
            mx=max(mx,sm+solve(piles,ind+1,c-i-1));
        }
        return dp[ind][c]=mx;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));           
        return solve(piles,0,k);
    }
};