// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    int r,c,ans=0,f;
    void dfs(vector<vector<int>>& g,int i,int j,int &cnt){
        if(i>=r || i<0 || j>=c || j<0 || g[i][j]!=1){
            if(i>=r || i<0 || j>=c || j<0) f=1;
            return;
        }
        g[i][j]=2;
        cnt+=1;
        dfs(g,i,j+1,cnt);
        dfs(g,i,j-1,cnt);
        dfs(g,i+1,j,cnt);
        dfs(g,i-1,j,cnt);
    }
    int numEnclaves(vector<vector<int>>& g) {
        r=g.size(),c=g[0].size();
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(g[i][j]==1){
                    f=0;
                    int cnt=0;
                    dfs(g,i,j,cnt);
                    if(!f)ans+=cnt;
                }
        return ans;                    
    }
};