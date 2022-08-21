class Solution {
public:
    int minimumRecolors(string b, int k) {
        int i=0,j=0,wc=0,mn=INT_MAX,n=size(b);
        while(j<n){
            if(b[j]=='W')++wc;
            if(j-i+1==k){
                mn=min(mn,wc);
                if(b[i]=='W')--wc;
                ++i;
            }
            ++j;
        }
        return mn;
    }
};