class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),b=0,mx=0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            if(r-l-1>mx){
                mx=r-l-1;
                b=l+1;
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            if(r-l-1>mx){
                mx=r-l-1;
                b=l+1;
            }
        }
        return s.substr(b,mx);
    }
};