// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        int t[n+1];
        t[0]=1;
        for(int i=1;i<=n;i++){
            t[i]=0;
            for(int j=0;j<i;j++)
                t[i]+=t[j]*t[i-j-1];
        }
        return t[n];
    }
};