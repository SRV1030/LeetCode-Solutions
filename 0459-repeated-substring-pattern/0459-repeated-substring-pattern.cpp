class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        if(n<2) return false;
        if(n==2) return s[0]==s[1];        
        vector<int>z(n);
        int l=0,r=0,mx=0;
        for(int k=1;k<n;k++){
            if(k>r){
                l=r=k;
                while(r<n && s[r-l]==s[r]) r++;
                z[k]=r-l;
                r--;
            }
            else{
                int k1=k-l;
                if(z[k1]<r-k+1)z[k]=z[k1];
                else{
                    l=k;
                    while(r<n && s[r]==s[r-l]) r++;
                    z[k]=r-l;
                    r--;
                }
            }
            if(z[k]>mx)mx=z[k];
        }
        int ln=n-mx;
        return mx>0 && n%ln==0 && z[ln]==mx;
        
    }
};