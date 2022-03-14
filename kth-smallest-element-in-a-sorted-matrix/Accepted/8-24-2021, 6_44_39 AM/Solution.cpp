// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),l=matrix[0][0],h=matrix[n-1][n-1],res=-1;
        while(l<h){
            int m=l+(h-l)/2;
            if(count(m,matrix)<k)l=m+1;
            else h=m;
        }
        return h;        
    }
    int count(int m,vector<vector<int>>& mat){
        int n=mat.size(),r=0,c=n-1,f=0;
        while(r<n && c>=0){
            if(mat[r][c]<=m){
                f+=c+1;
                r++;
            }
            else c--;
        }
        return f;
    }
};