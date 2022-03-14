// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    int numDistinct(string s, string r) {
        int ns=s.length(),nr=r.length();
        int t[nr+1][ns+1],c=0;
        memset(t,0,sizeof(t));
        t[0][0]=1;
        for(int i=1;i<=nr;i++){
            int sum=t[i-1][0];
            for(int j=1;j<=ns;j++){
                if(r[i-1]==s[j-1]){
                    t[i][j]+=sum;
                    if(i==nr) c+=t[i][j];
                }
                sum+=t[i-1][j];
            }
        }
        return c;
    }
};