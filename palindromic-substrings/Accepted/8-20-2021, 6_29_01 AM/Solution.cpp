// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int countSubstrings(string s) {
        int c=0,n=s.size();
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n){
                if(s[l--]==s[r++])c++;
                else break;
             }   
            l=i,r=i+1;
            while(l>=0 && r<n){
                if(s[l--]==s[r++])c++;
                else break;
             }   
        }
        return c;
    }
};