// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    void DFS(vector<vector<int>>& isCon,int i,int n){
        isCon[i][i]=2;
        for(int j=0;j<n;j++){
                if(isCon[j][j]==1 &&isCon[i][j]==1){
                    DFS(isCon,j,n);
                }            
        }
    }
    int findCircleNum(vector<vector<int>>& isCon) {
        int c=0;
        int n=isCon.size();
        // int m=isCon[0].size();
        for(int i=0;i<n;i++){
                if(isCon[i][i]==1){
                    DFS(isCon,i,n);
                    c++;
                }            
        }
        return c;
    }
};