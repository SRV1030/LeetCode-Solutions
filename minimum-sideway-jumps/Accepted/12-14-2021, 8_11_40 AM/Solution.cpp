// https://leetcode.com/problems/minimum-sideway-jumps

class Solution {
public: int mnj=INT_MAX;
    vector<vector<int>>dp;
    int jump(int side,vector<int>& obs,int cp){        
        if(cp==obs.size()-2) return dp[cp][side]=0;
        if(dp[cp][side]!=-1) return dp[cp][side];
        if(obs[cp+1]!=side) return dp[cp][side]=jump(side,obs,cp+1);
        else{   
            int s1,s2;
            if(side==1){s1=2;s2=3;}
            else if(side==2){s1=1;s2=3;}
            else {s1=1;s2=2;}
            if(obs[cp]==s1)return dp[cp][side]=1+jump(s2,obs,cp);
            else if(obs[cp]==s2) return dp[cp][side]=1+jump(s1,obs,cp);
            else return dp[cp][side]=1+min(jump(s2,obs,cp),jump(s1,obs,cp));
        }
        return dp[cp][side]=0;        
    }
    int minSideJumps(vector<int>& obs) {
        dp=vector<vector<int>>(obs.size()+1,vector<int>(4,-1));        
        return jump(2,obs,0);
    }
};