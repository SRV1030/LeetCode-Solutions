// https://leetcode.com/problems/matrix-block-sum


// This question is similar to a vector segment sum.

// To extract sum of an arbitrary sub-array, we first form a prefix sum array.
// [1, 2, 3, 4, 5] // original vector
// [1, 3, 6, 10, 15] // prefix sum

// To get sum of a sub array from index a to index b, sum(a, b), we can instead calculate prefix(b) - prefix(a-1)

// Similar in 2D, we form prefix matrix, where sum[i][j] = sum of elements on top left of original matrix
// [1, 2, 3]
// [4, 5, 6]
// [7, 8, 9]

// [1, 3, 6]
// [5, 12, 21]
// [12, 27, 45]

// Similarly, Sum of an arbitrary block from (i-K, j-K) to (i+K, j+K)
// ans(i, j) = prefix(i+K, j+K) - prefix(i+K, j-K-1) - prefix (i-K-1, j+K) + prefix(i-K-1, j-K-1);
// https://www.youtube.com/watch?v=jor18pkf9EE


class Solution {
public:
    vector<vector<int>>sum;
    int r,c;
    int getS(int i,int j){
        if(i<0 || j<0) return 0;
        i=(i>=r)?r-1:i;
        j=(j>=c)?c-1:j;
        return sum[i][j];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        r=mat.size(),c=mat[0].size();
        vector<vector<int>> ans=vector<vector<int>>(r,vector<int>(c,0));
        sum=ans;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                sum[i][j]=mat[i][j]+getS(i-1,j)+getS(i,j-1)-getS(i-1,j-1);        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                ans[i][j]=getS(i+k,j+k)+getS(i-k-1,j-k-1)-getS(i+k,j-k-1)-getS(i-k-1,j+k);
        return ans;
    }
};