// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int p=1;
        int i=0,j=0,r=n,c=n;
        vector<vector<int>> v(n,vector<int>(n));
        while(i<r && j<c){
            for(int k=j;k<c;k++) v[i][k]=p++;
            i++;
            for(int k=i;k<r;k++) v[k][c-1]=p++;
            c--;
            if(j<c){
                for(int k=c-1;k>=j;k--) v[r-1][k]=p++;
                r--;
            }
            if(i<r){
                for(int k=r-1;k>=i;k--) v[k][j]=p++;
                j++;
            }
        }
        return v;
    }
};