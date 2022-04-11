class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int m=g.size(),n=g[0].size(),d=m*n;
        k%=d;
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                int nj=(j+k)%n,ni=(i+(j+k)/n)%m;
                ans[ni][nj]=g[i][j];
            }
        return ans;
    }
};