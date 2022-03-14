// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int i=0,j=0,r=mat.size(),c=mat[0].size();
        vector<int> ans;
        while(i<r && j<c){
            for(int k=j;k<c;k++)ans.push_back(mat[i][k]);
            i++;
            for(int k=i;k<r;k++)ans.push_back(mat[k][c-1]);
            c--;
            if(i<r){
               for(int k=c-1;k>=j;k--)ans.push_back(mat[r-1][k]);
               r--; 
            }
            if(j<c){
               for(int k=r-1;k>=i;k--)ans.push_back(mat[k][j]);
               j++; 
            }
        }
        return ans;
    }
}; 
            
      
        