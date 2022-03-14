// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size()-1;
        int c=matrix[0].size()-1;
        int x=0,f=0;
        for(int i=0;i<=r;i++){
            if(target == matrix[i][c]) return true;
            if(target<matrix[i][c]){
                x=i;
                f=1;
                break;
            }
        }
        if(f==0) return false;
        int y=0;
        while(y<c){
            int m=(y+c)/2;
            if(matrix[x][m]==target) return true;
            else if (matrix[x][m]<target)y=m+1;
            else c=m-1;            
        }
        return false;
        
    }
};