class Solution {
public: int r,c,f;
    void dfs(vector<vector<int>>& g,int i,int j){
        if(i>=r || i<0 || j>=c || j<0 || g[i][j]!=0){
            if(i>=r || i<0 || j>=c || j<0) f=1;
            return;
        }
        g[i][j]=2;
        dfs(g,i,j+1);
        dfs(g,i,j-1);
        dfs(g,i+1,j);
        dfs(g,i-1,j);
    }
    int closedIsland(vector<vector<int>>& g) {
        int ans=0;
        r=g.size(),c=g[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]==0){                    
                    f=0;
                    dfs(g,i,j);
                    if(!f)ans++;
                }
            }
        }
        return ans;
    }
};