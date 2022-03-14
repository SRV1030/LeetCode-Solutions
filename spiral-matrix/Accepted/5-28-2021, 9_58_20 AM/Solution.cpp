// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j=0,r=matrix.size(),c=matrix[0].size();
        vector<int> v;
        while(i<r && j<c){
            for(int k=j;k<c;k++)v.push_back(matrix[i][k]);
            i++;
            for(int k=i;k<r;k++)v.push_back(matrix[k][c-1]);
            c--;
            if(i<r){
                for(int k=c-1;k>=j;k--)v.push_back(matrix[r-1][k]);
                r--;
            }
            if(j<c){
                for(int k=r-1;k>=i;k--)v.push_back(matrix[k][j]);
                j++;
            }
            
            
        }
        return v;
        
    }
};