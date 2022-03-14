// https://leetcode.com/problems/stone-game

// class Solution {
// public:    
//     int dp[501][501];
//     int solve(vector<int>& piles,int i,int j){
//         if(i>j) return 0;
//         if(i==j) return dp[i][j]=piles[i];
//         if(dp[i][j]!=-1) return -1;
//         int l=piles[i]+solve(piles,i+1,j);
//         int r=piles[j]+solve(piles,i,j-1);
//         return dp[i][j]=max(l,r);
//     }
//     bool stoneGame(vector<int>& piles) {
//         memset(dp,-1,sizeof(dp));
//         int s=0;
//         for(auto&i:piles)s+=i;
//         int alice=solve(piles,0,piles.size()-1);
//         // cout<<alice<<" ";
//         return 2*alice>s;//alice>s-alice[bob=s-alice]        
//     }
// };

class Solution {
public:
    bool stoneGame(vector<int>& piles) {        
        return true;       
    }
};