class Solution {
public:
    int dp[6005][2]={{0}},inf=1e9;
    set<int>st;
    int jump(int pos,int a,int b,int x,int cnt){
        if(pos==x)return 0;
        if(st.count(pos) || pos<0 || pos>6000) return inf;
        if(dp[pos][cnt]) return dp[pos][cnt];
        dp[pos][cnt]=1+jump(pos+a,a,b,x,0);
        return dp[pos][cnt]=min(dp[pos][cnt],cnt==0?1+jump(pos-b,a,b,x,1):dp[pos][cnt]);
    }
    int minimumJumps(vector<int>& f, int a, int b, int x) {
        st=set<int>(f.begin(),f.end());
        int ans= jump(0,a,b,x,0);
        return (ans>=inf)?-1:ans;
    }
};