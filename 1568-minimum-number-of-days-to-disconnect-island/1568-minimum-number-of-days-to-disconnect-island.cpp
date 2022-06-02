class Solution {
public:
    int isLands=0,o=0,r,c;
    int vis[31][31];
    void dfs(vector<vector<int>>& g,int i,int j){
        if(i<0 || i>=r || j<0 || j>=c || vis[i][j] || !g[i][j]) return;
        vis[i][j]=1;
        dfs(g,i+1,j);
        dfs(g,i-1,j);
        dfs(g,i,j+1);
        dfs(g,i,j-1);        
    }
    void countALL(vector<vector<int>>& g){
        isLands=0,o=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j){
                if(!vis[i][j]&&g[i][j])dfs(g,i,j),isLands++;
                if(g[i][j])o++;
            }
    }
    int minDays(vector<vector<int>>& g) {
        r=g.size();
        c=g[0].size();
        countALL(g);
        if(isLands!=1) return 0;
        if(r==1 || c==1 || o<=2) return o==2?2:1;
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j){
                if(g[i][j]){
                    g[i][j]=0;
                    countALL(g);
                    if(isLands>1) return 1;
                    g[i][j]=1;
                }
            }
        return 2;
    }
};