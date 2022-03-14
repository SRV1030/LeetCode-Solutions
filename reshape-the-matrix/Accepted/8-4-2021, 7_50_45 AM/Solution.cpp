// https://leetcode.com/problems/reshape-the-matrix

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int R=mat.size(),C=mat[0].size();
        if(r*c!=R*C) return mat;
        vector<vector<int>> ans(r,vector<int>(c));
        int x=0,y=0;
        for(auto& i:mat){
            for(auto& j:i){
                if(y>=c){
                    x++;y=0;
                }
                ans[x][y++]=j;
            }                
        }
        return ans;
    }
};