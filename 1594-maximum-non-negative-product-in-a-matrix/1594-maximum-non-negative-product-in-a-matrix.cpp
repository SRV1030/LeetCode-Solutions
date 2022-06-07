#define li long long int
class Solution {
public:
    int md=1e9+7;
    int maxProductPath(vector<vector<int>>& g) {
        int n=size(g),m=size(g[0]);
        vector<vector<li>>mx(n,vector<li>(m));
        mx[0][0]=g[0][0];
        for(int i=1;i<n;++i)mx[i][0]=mx[i-1][0]*g[i][0];
        for(int i=1;i<m;++i)mx[0][i]=mx[0][i-1]*g[0][i];
        vector<vector<li>>mn=mx;
        for(int i=1;i<n;++i)
            for(int j=1;j<m;++j){
                if(g[i][j]>=0){
                    mx[i][j]=max(mx[i-1][j],mx[i][j-1])*g[i][j];
                    mn[i][j]=min(mn[i-1][j],mn[i][j-1])*g[i][j];
                }else{
                    mx[i][j]=min(mn[i-1][j],mn[i][j-1])*g[i][j];
                    mn[i][j]=max(mx[i-1][j],mx[i][j-1])*g[i][j];
                }
            }
        if(mx[n-1][m-1]<0)return -1;
        return mx[n-1][m-1]%md;
    }
};