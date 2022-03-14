// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
   
private:
    vector<int> x = {-1,-1,-1,0,0,1,1,1};
    vector<int> y = {-1,0,1,-1,1,-1,0,1};
public:     
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
         int n=g.size();
        if (g[0][0] || g[n-1][n-1]) 
            return -1;
        queue<pair<int,int>>pq;
        pq.push({0,0});
        g[0][0]=1;
        while(!pq.empty() && !g[n-1][n-1]){
            pair<int,int>c=pq.front();
            pq.pop();
            for(int i=0;i<8;i++){
                int dx=c.first+x[i];
                int dy=c.second+y[i];
                if(dx>=0 && dx<n && dy>=0 && dy<n && g[dx][dy]==0){
                    g[dx][dy]= g[c.first][c.second]+1;
                    pq.push({dx,dy});                    
                }
            }
            
        }
        return g[n-1][n-1]?g[n-1][n-1]:1;
    }
};