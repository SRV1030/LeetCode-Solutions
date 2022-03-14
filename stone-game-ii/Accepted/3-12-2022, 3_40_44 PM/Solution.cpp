// https://leetcode.com/problems/stone-game-ii

class Solution {
public:
    int dp[101][10005]={};
    int n;
    int solve(vector<int>&p,int i,int m){
        if(i>=n) return 0;        
        if(dp[i][m]) return dp[i][m];
        int res=INT_MIN,tot=0;
        for(int j=0;j<2*m;j++){
            if(i+j<n)tot+=p[i+j];
            res=max(res,tot-solve(p,i+j+1,max(m,j+1)));
        }
        return dp[i][m]=res;   
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        int s=0;
        for(auto&i:piles)s+=i;
        return (s+solve(piles,0,1))/2;
    }
};