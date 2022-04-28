class Solution {
public:
    vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& h) {
        int m=h.size(),n=h[0].size();
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<>>pq;
        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty()){
            auto[dif,ind]=pq.top();
            pq.pop();
            int i=ind[0],j=ind[1];
            if(i==m-1 && j==n-1) return dif;
            for(auto&d:dir){
                int x=i+d[0],y=j+d[1];
                if(x<0 || y<0 || x>=m || y>=n) continue;
                int nd=max(dif,abs(h[i][j]-h[x][y]));
                if(nd<dis[x][y]){
                    dis[x][y]=nd;
                    pq.push({nd,{x,y}});
                }
                
            }
        }
        return 0;
    }
};