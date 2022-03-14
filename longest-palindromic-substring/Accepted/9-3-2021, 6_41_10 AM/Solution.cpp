// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        string res,t;
        res+=s[0];
        int n=s.size();
        for(int i=0;i<n;i++){
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            t=s.substr(l+1,r-l-1);
            if(t.size()>res.size())res=t;
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;r++;
            }
            t=s.substr(l+1,r-l-1);
            if(t.size()>res.size())res=t;
        }
        return res;
    }
};