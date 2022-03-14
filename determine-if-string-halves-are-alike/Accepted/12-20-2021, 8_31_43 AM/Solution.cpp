// https://leetcode.com/problems/determine-if-string-halves-are-alike

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        if(n%2)return false;
         
        int prev=0;
        int next=0;
        
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]=='A'||s[i]=='a'||s[i]=='E'||s[i]=='e'||s[i]=='I'||s[i]=='i'||s[i]=='O'||s[i]=='o'||s[i]=='U'||s[i]=='u')
                prev++;
        }
        
        for(int i=s.length()/2;i<s.length();i++)
        {
            if(s[i]=='A'||s[i]=='a'||s[i]=='E'||s[i]=='e'||s[i]=='I'||s[i]=='i'||s[i]=='O'||s[i]=='o'||s[i]=='U'||s[i]=='u')
                next++;
        }
        
        if(next==prev)
            return true;
        
        else
            return false;
    }
};