// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        for(int i=1;i<g[0].size();i++)g[0][i]+=g[0][i-1];
        for(int i=1;i<g.size();i++){
            g[i][0]+=g[i-1][0];
            for(int j=1;j<g[0].size();j++)
                g[i][j]+=min(g[i-1][j],g[i][j-1]);
        }
        return g[g.size()-1][g[0].size()-1];
    }
};