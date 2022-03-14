// https://leetcode.com/problems/range-sum-query-2d-immutable

class NumMatrix {
public:
    vector<vector<int>> sum;
    int r,c;
    int getS(int i,int j){
        if(i<0 || j<0) return 0;
        return sum[i][j];
    }
    NumMatrix(vector<vector<int>>& mat) {
        r=mat.size();
        c=mat[0].size();
        sum=vector<vector<int>>(r,vector<int>(c));
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                sum[i][j]=mat[i][j]+getS(i-1,j)+getS(i,j-1)-getS(i-1,j-1);
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getS(row2,col2)-getS(row2,col1-1)-getS(row1-1,col2)+getS(row1-1,col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */