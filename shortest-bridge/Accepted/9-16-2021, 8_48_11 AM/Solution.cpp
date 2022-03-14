// https://leetcode.com/problems/shortest-bridge

class Solution {
public:
    queue<pair<int,int>>q;
    int r,c;
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& g,int i,int j){
        g[i][j]=2;
        q.push({i,j});
        for(auto& d:dir){
            int x=i+d[0],y=j+d[1];
            if(x>=r||x<0||y>=c||y<0||g[x][y]==2||g[x][y]==0)continue;
            dfs(g,x,y);
        }        
    }
    int shortestBridge(vector<vector<int>>& g) {
        r=g.size(),c=g[0].size();
        bool i1f=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]==1){
                    dfs(g,i,j);
                    i1f=true;
                    break;
                }
            }
            if(i1f) break;
        }
        int ans=0;
        while(!q.empty()){
            ans++;
            int n=q.size();
            while(n--){
                auto [i,j]=q.front();
                q.pop();
                for(auto& d:dir){
                    int x=i+d[0],y=j+d[1];
                    if(x>=r||x<0||y>=c||y<0||g[x][y]==2)continue;
                    if(g[x][y]==1) return ans-1;
                    g[x][y]=2;
                    q.push({x,y});
                }  
            }
        }
        return ans-1;
    }
};