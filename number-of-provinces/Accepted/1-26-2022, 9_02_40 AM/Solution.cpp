// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    int n;
    void dfs(vector<vector<int>>& isCon,int i){
        isCon[i][i]=2;
        for(int j=0;j<n;j++)
            if(isCon[j][j]==1 && isCon[i][j]==1)dfs(isCon,j);
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        n=isCon.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(isCon[i][i]==1){
                dfs(isCon,i);
                c++;
            }
        }
        return c;
    }
};