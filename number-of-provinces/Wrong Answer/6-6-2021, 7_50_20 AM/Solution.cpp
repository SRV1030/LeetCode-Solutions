// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void DFS(vector<vector<int>>& isCon,int i,int j,int n,int m){
        isCon[i][j]=2;
        if(i+1<n)
            if(isCon[i+1][j]==1) DFS(isCon,i+1,j,n,m);
        if(i-1>=0)
            if(isCon[i-1][j]==1) DFS(isCon,i-1,j,n,m);
        if(j+1<m)
            if(isCon[i][j+1]==1) DFS(isCon,i,j+1,n,m);
        if(j-1>=0)
            if(isCon[i][j-1]==1) DFS(isCon,i,j-1,n,m);
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        int c=0;
        int n=isCon.size();
        int m=isCon[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isCon[i][j]==1){
                    DFS(isCon,i,j,n,m);
                    c++;
                }
            }
        }
        return c;
    }
};