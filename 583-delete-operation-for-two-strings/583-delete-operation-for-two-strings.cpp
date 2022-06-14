class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1=size(w1),n2=size(w2);
        int t[n1+1][n2+1];
        for(int i=0;i<=n1;++i)
            for(int j=0;j<=n2;++j){
                if(i==0 || j==0)t[i][j]=0;
                else{
                    if(w1[i-1]==w2[j-1])t[i][j]=1+t[i-1][j-1];
                    else t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        return n1+n2-2*t[n1][n2];
    }
};