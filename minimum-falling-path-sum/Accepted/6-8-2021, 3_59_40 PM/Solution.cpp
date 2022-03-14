// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=1;i<n;i++){
            mat[i][0]+=min(mat[i-1][0],mat[i-1][1]);
            for(int j=1;j<n-1;j++) 
                mat[i][j]+=min(mat[i-1][j-1],min(mat[i-1][j],mat[i-1][j+1]));
            mat[i][n-1]+=min(mat[i-1][n-1],mat[i-1][n-2]);
        }
        return *min_element(mat[n-1].begin(),mat[n-1].end());
    }
};