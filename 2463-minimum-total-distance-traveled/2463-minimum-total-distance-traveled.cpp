#define ll long long
class Solution {
public:
    vector<vector<vector<ll>>> dp;
    ll solve(int i,int j,int k,vector<int>& rb, vector<vector<int>>& fc){
        if(i==size(rb))return 0;
        if(j==size(fc)) return 1e16;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        ll res1=solve(i,j+1,0,rb,fc),res2=k<fc[j][1]?solve(i+1,j,k+1,rb,fc)+abs(fc[j][0]-rb[i]):1e16;
        return dp[i][j][k]=min(res1,res2); 
        
    }
    long long minimumTotalDistance(vector<int>& rb, vector<vector<int>>& fc) {
        sort(begin(rb),end(rb));
        sort(begin(fc),end(fc));
        dp=vector<vector<vector<ll>>>(rb.size(), vector<vector<ll>>(fc.size(), vector<ll>(rb.size(), -1)));
        return solve(0,0,0,rb,fc);
    }
};