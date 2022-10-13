class Solution {
public:
    int hsum(int i,int j,vector<vector<int>>& g){
        return g[i][j-1]+g[i][j]+g[i][j+1]+g[i+1][j]+g[i+2][j]+g[i+2][j-1]+g[i+2][j+1];
    }
    int maxSum(vector<vector<int>>& g) {
        int mx=0,r=size(g),c=size(g[0]);
        for(int i=0;i<r-2;++i)
            for(int j=1;j<c-1;++j)
                mx=max(mx,hsum(i,j,g));
        return mx;
    }
};