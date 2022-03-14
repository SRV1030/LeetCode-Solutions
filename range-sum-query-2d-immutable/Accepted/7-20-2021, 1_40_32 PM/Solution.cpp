// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public: vector<vector<int>>sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        sum = vector(n+1,vector<int>(matrix[0].size()+1,0));
        
        for(int i=0;i<n;i++){
            int m = matrix[i].size();
           for(int j=0;j<m;j++) {
               sum[i+1][j+1] = matrix[i][j]+sum[i+1][j];
           }
        }
        
        for(int j=1;j<matrix[0].size()+1;j++){
            for(int i=1;i<n+1;i++){
                sum[i][j] += sum[i-1][j];
            }
        }       
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1]-sum[row2+1][col1]+sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */