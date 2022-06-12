class Solution {
public:
    int minPathCost(vector<vector<int>>& g, vector<vector<int>>& moveCost) {
        int r=size(g),c=size(g[0]);
        vector<vector<int>>ans=g;
        for(int i=1;i<r;++i){            
            for(int j=0;j<c;++j){
                int x=INT_MAX;
                for(int k=0;k<c;++k)x=min(x,g[i][j]+ans[i-1][k]+moveCost[g[i-1][k]][j]);
                ans[i][j]=x;
            }            
        }
        return *min_element(begin(ans[r-1]),end(ans[r-1]));
    }
};