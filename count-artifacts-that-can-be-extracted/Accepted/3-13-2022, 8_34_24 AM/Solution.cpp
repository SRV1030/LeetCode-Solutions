// https://leetcode.com/problems/count-artifacts-that-can-be-extracted

class Solution {
public:
    bool check(vector<vector<int>> &g,int &r1,int &c1,int &r2,int &c2){
        for(int i=r1;i<=r2;i++)
            for(int j=c1;j<=c2;j++)
                if(g[i][j]!=1) return false;
        return true;
    }
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>>g(n,vector<int>(n));
        for(auto&i:dig)g[i[0]][i[1]]=1;
        int artf=0;
        for(auto&i:artifacts)
            if(check(g,i[0],i[1],i[2],i[3]))artf++;
        return artf;
    }
};