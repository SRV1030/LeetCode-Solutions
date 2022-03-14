// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size()-1;
        int c=matrix[0].size()-1;
        int i;
        if(r!=0){
            for(i=0;i<=r;i++){
            if(target == matrix[i][c]) return true;
            if(target<matrix[i][c]) break;
            
        }
        }
        else{
            i=r;
        }
        if(i>r) return false;
        int y=0;
        while(y<c){
            int m=(y+c)/2;
            if(matrix[i][m]==target) return true;
            else if (matrix[i][m]<target)y=m+1;
            else c=m-1;            
        }
        return false;
        
    }
};