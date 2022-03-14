// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string res;
        res+=s[0];
        for(int i=0;i<n-1;i++){
            int l=i,r=i;
            string t;
            while(l>=0 && r<n){
                if(s[l]!=s[r])break;
                l--;
                r++;
            }
            l++;
            r--;
            t=s.substr(l,r-l+1);
            if(t.length()>res.length()) res=t;
            l=i-1,r=i;
            while(l>=0 && r<n){
                if(s[l]!=s[r])break;
                l--;
                r++;
            }
            l++;
            r--;
            t=s.substr(l,r-l+1);
            if(t.length()>res.length()) res=t;
        }
        return res;
        
    }
};