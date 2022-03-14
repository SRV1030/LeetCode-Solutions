// https://leetcode.com/problems/minimum-score-triangulation-of-polygon

class Solution {
public:
    int dp[50][50]={};
    int minScoreTriangulation(vector<int>& v,int i=0,int j=0) {
        if(j==0) j=v.size()-1;
        if(i>=j || j-i<2) return 0;
        if(dp[i][j]!=0) return dp[i][j];
        int res=INT_MAX;
        for(int k=i+1;k<j;k++){
            int t=minScoreTriangulation(v,i,k)+v[i]*v[k]*v[j]+minScoreTriangulation(v,k,j);
            res=min(res,t);
        }
        return dp[i][j]=res;
    }
};