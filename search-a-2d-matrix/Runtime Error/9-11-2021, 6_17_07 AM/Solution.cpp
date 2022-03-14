// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r=mat.size(),c=mat[0].size(),l=0,h=r+c-1;
        while(l<=h){
            int m=l+(h-l)/2,x=m/2,y=m%2;            
            if(mat[x][y]==target) return true;
            if(mat[x][y]>target)h=m-1;
            else l=m+1;
        }
        return false;
    }
};