// https://leetcode.com/problems/01-matrix

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& isW) {
        int r=isW.size(),c=isW[0].size();
        vector<vector<int>>ans(r,vector<int>(c,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(!isW[i][j])
                    q.push({i,j});                    
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int x=q.front().first,y=q.front().second;
                q.pop();
                if(ans[x][y]>lvl){
                    ans[x][y]=lvl;
                    for(int d=0;d<4;d++){
                        int i=x+dx[d],j=y+dy[d];
                        if(i<0 || i>=r || j<0 || j>=c) continue;
                        q.push({i,j});
                    }
                }
            }
            lvl++;
        }
        return ans;            
    }
};