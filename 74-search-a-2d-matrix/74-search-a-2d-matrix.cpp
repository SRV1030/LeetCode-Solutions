class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& mat, int target) {
    //     int r=mat.size(),c=mat[0].size(),l=0,h=r*c-1;
    //     while(l<=h){
    //         int m=l+(h-l)/2,x=m/c,y=m%c;            
    //         if(mat[x][y]==target) return true;
    //         if(mat[x][y]>target)h=m-1;
    //         else l=m+1;
    //     }
    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r=mat.size(),c=mat[0].size(),l=0,h=c-1;
        while(l<r && h>=0){
            if(mat[l][h]==target) return 1;
            if(mat[l][h]>target)h--;
            else l++;
        }
        return 0;
    }
};