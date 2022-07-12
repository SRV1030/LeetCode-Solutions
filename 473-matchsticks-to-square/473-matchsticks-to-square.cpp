class Solution {
public:
    vector<int>vis;
    bool makesquare(vector<int>& ms) {
        int sm=0,n=size(ms);
        sm=accumulate(begin(ms),end(ms),sm);
        if(sm%4 || n<4)return false;
        vis.resize(n);
        return solve(ms,sm/4,0,0,4);
    }
    bool solve(vector<int>& ms,int tg,int s,int i,int k){
        if(k==1) return true;
        if(s==tg) return solve(ms,tg,0,0,k-1);
        for(int j=i;j<size(ms);++j){
            if(vis[j] || ms[j]+s>tg) continue;
            vis[j]=1;
            if(solve(ms,tg,s+ms[j],j+1,k)) return true;
            vis[j]=0;
        }
        return false;
    }
};