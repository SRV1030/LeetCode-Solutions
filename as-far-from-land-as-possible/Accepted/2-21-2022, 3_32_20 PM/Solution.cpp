// https://leetcode.com/problems/as-far-from-land-as-possible

class Solution {
public:
    int x[4] = {1,0,-1,0};
    int y[4] = {0,1,0,-1};
    int maxDistance(vector<vector<int>>& grid) {
        int mx = -1;
        int n = grid.size();
        vector<vector<int>>dis(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int>p = q.front();
            q.pop();
            for(int dir=0;dir<4;dir++)
            {
                int pos_x = p.first+x[dir];
                int pos_y = p.second+y[dir];
                if(pos_x>=0 && pos_x<n && pos_y >=0 && pos_y <n && dis[pos_x][pos_y]==-1)
                {
                    dis[pos_x][pos_y] = dis[p.first][p.second]+1;
                    mx = max(mx,dis[pos_x][pos_y]);
                    q.push({pos_x,pos_y});
                }
            }
        }
        return mx;
    }
};