// https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods

class Solution {
public:
    vector<vector<int>>dp;
    int solve(string s,int l,int r,int cnt){
        if(l==r)return dp[l][r]=(s[l]=='1');
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int left=solve(s,l+1,r,(s[l]=='1')?(cnt-1):cnt)+1;
        int right=solve(s,l,r-1,(s[r]=='1')?(cnt-1):cnt)+1;
        int cur=cnt*2;
        return dp[l][r]=min({cur,left,right});
    }
    int minimumTime(string s) {
        int n=s.size(),cnt=0;
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        for(auto c:s){
            if(c=='1')cnt++;
        }
        return solve(s,0,s.size()-1,cnt);
    }
};