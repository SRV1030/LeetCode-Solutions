// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1=w1.length(),n2=w2.length();
        int t[n1+1][n2+1];
        for(int i=0;i<=n1;i++)
            for(int j=0;j<=n2;j++){
                if(i==0) t[i][j]=j;
                else if(j==0) t[i][j]=i;
                else{
                    if(w1[i-1]==w2[j-1])t[i][j]=t[i-1][j-1];
                    else t[i][j]=1+min(t[i-1][j],min(t[i][j-1],t[i-1][j-1]));
                }
            }
        return t[n1][n2];
    }
};