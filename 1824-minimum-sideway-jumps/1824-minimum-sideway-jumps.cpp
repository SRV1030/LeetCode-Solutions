class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int jump(vector<int>& obs,int side,int cp){
        if(cp==n-2)return dp[cp][side]=0;
        if(dp[cp][side]!=-1) return dp[cp][side];
        if(obs[cp+1]!=side)return jump(obs,side,cp+1);
        else{
            int s1,s2;
            if(side==1)s1=2,s2=3;
            else if(side==2)s1=1,s2=3;
            else s1=1,s2=2;
            if(obs[cp]==s1)return dp[cp][side]=1+jump(obs,s2,cp);
            if(obs[cp]==s2)return dp[cp][side]=1+jump(obs,s1,cp);
            return dp[cp][side]=1+min(jump(obs,s2,cp),jump(obs,s1,cp));
        }
        return dp[cp][side]=0;
    }
    int minSideJumps(vector<int>& obs) {
        n=obs.size();
        dp=vector<vector<int>>(n+1,vector<int>(4,-1));
        return jump(obs,2,0);
    }
};