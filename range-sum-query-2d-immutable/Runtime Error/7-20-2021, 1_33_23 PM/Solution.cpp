// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public: vector<vector<int>>s;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>>sum(n+1,vector<int>(m+1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum[i+1][j+1]=matrix[i][j]+sum[i+1][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                sum[i][j]+=sum[i-1][j];
            }
        }
        s=sum;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2+1][col2+1] - s[row1][col2+1]-s[row2+1][col1]+s[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */