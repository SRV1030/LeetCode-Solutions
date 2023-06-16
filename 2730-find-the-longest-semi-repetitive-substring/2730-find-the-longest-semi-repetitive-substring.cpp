class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int i=0,j=1,n=size(s),pv=-1,mx=1;
        while(j<n){
            if(s[j]==s[j-1]){
                if(pv!=-1)i=pv;
                pv=j;
            }
            mx=max(mx,j-i+1);
            ++j;
        }
        return mx;
    }
};