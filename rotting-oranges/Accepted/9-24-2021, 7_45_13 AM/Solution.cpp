// https://leetcode.com/problems/rotting-oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pair<int,int>>q;
        int c=0,r=0;
        int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<g.size();i++)
            for(int j=0;j<g[i].size();j++)
                if(g[i][j]){
                    c++;
                    if(g[i][j]==2) q.push({i,j});
                }
        int m=0;
        while(!q.empty()){
            int n=q.size();            
            r+=n;
            while(n--){
                int x=q.front().first,y=q.front().second;
                q.pop();
                for(int d=0;d<4;d++){
                    int i=x+dir[d][0],j=y+dir[d][1];
                    if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j]==0 || g[i][j]==2) continue;
                    g[i][j]=2;
                    q.push({i,j});
                }
            }
            if(!q.empty())m++;
        }
        return r==c?m:-1;
    }
};