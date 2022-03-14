// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1=w1.size(),n2=w2.size();
        int t[n1+1][n2+1];
        for(int i=0;i<=n1;i++)t[i][0]=i;
        for(int i=1;i<=n2;i++)t[0][i]=i;
        for(int i=1;i<=n1;i++)
            for(int j=1;j<=n2;j++){
                if(w1[i-1]==w2[j-1])t[i][j]=t[i-1][j-1];
                else t[i][j]=1+min(t[i-1][j-1],min(t[i-1][j],t[i][j-1]));
            }
        return t[n1][n2];
    }
};