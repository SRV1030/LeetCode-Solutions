class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res=0,r=size(mat),c=size(mat[0]);
        int dp[151][151]={};
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j){
                if(j==0)dp[i][j]=mat[i][j];
                else if(mat[i][j])dp[i][j]=mat[i][j]+dp[i][j-1];
                int mn=dp[i][j];
                for(int k=i;k>=0;--k){
                    mn=min(mn,dp[k][j]);
                    res+=mn;
                }
            }
        return res;
    }
};